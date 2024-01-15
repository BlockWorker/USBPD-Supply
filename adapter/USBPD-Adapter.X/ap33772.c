#include "ap33772.h"
#include "mcc_generated_files/pin_manager.h"
#include "i2c_blocking.h"
#include "util.h"
#include "ui.h"


#define AP_I2C_ADDR 0x51
#define AP_I2C_INST I2CB_I2C1
#define AP_MEASURE_INTERVAL 100000


AP_VoltageOption ap_voltage_options[7];
uint8_t ap_voltage_option_count = 0;

static bool _ap_interruptTriggered = false;
static uint64_t _ap_lastMeasurement = 0;


static void _ap_interruptCallback() {
    _ap_interruptTriggered = true;
}


bool AP_Reset() {
    //return I2CB_Write40(AP_I2C_INST, AP_I2C_ADDR, 0x30); //write RDO 0x00000000
    return I2CB_Write16(AP_I2C_INST, AP_I2C_ADDR, 0x0024); //set OTP threshold to zero (force OTP)
}

bool AP_SendRDO(uint8_t option, int32_t voltagex10mV, int32_t currentx10mA) {
    if (option > ap_voltage_option_count) return false;
    
    AP_VoltageOption* opt = ap_voltage_options + option;
    AP_RDO rdo;
    uint16_t ocp_th;
    
    //populate RDO with given values
    if (opt->adjustable) {
        AP_PRDO* prdo = &(rdo.prdo);
        prdo->pdoIndex = opt->pdoIndex;
        prdo->voltagex20mV = voltagex10mV / 2;
        prdo->currentx50mA = currentx10mA / 5;
        ocp_th = prdo->currentx50mA + 2; //OCP 100mA above setpoint
    } else {
        AP_FRDO* frdo = &(rdo.frdo);
        frdo->pdoIndex = opt->pdoIndex;
        frdo->minCurrentx10mA = frdo->maxCurrentx10mA = opt->maxCurrentx10mA;
        ocp_th = frdo->maxCurrentx10mA / 5 + 2; //OCP 100mA above max
    }
    
    asserttrue(I2CB_Write16(AP_I2C_INST, AP_I2C_ADDR, (ocp_th << 8) | 0x23)); //write new OCP threshold
    asserttrue(I2CB_Write16(AP_I2C_INST, AP_I2C_ADDR, 0x7824)); //restore OTP threshold to normal
    
    //convert RDO to integer and write to I2C
    uint64_t rdo_data = *(uint32_t*)(&rdo);
    return I2CB_Write40(AP_I2C_INST, AP_I2C_ADDR, (rdo_data << 8) | 0x30);
}

bool AP_Initialize() {
    ap_voltage_option_count = 0;
    _ap_interruptTriggered = true; //force status read after init
    _ap_lastMeasurement = 0;
    
    USB_INT_SetInterruptHandler(&_ap_interruptCallback);
    
    asserttrue(I2CB_Write16(AP_I2C_INST, AP_I2C_ADDR, 0x311E)); //enable interrupt for ready bit and OTP/OCP/OVP
    asserttrue(I2CB_Write24(AP_I2C_INST, AP_I2C_ADDR, /*(10000 << 8) | */0x271028)); //thermistor resistances at 25/50/75/100°C
    asserttrue(I2CB_Write24(AP_I2C_INST, AP_I2C_ADDR, /*(4165 << 8) | */0x10542A));
    asserttrue(I2CB_Write24(AP_I2C_INST, AP_I2C_ADDR, /*(1929 << 8) | */0x07892C));
    asserttrue(I2CB_Write24(AP_I2C_INST, AP_I2C_ADDR, /*(956 << 8) | */0x03BC2E));
    return AP_Reset();
}

void AP_Tasks() {
    AP_PDO pdos[7];
    
    if (_ap_interruptTriggered) { //handle interrupt -> status change
        _ap_interruptTriggered = false;
        
        int16_t status = I2CB_CmdRead8(AP_I2C_INST, AP_I2C_ADDR, 0x1D);
        if (status >= 0) { //valid status?
            bool ready = (status & 0x01) > 0; //ready bit
            
            if ((status & 0x30) > 0 || (ready && (status & 0x02) == 0)) { //OTP/OCP/OVP triggered, or negotiation unsuccessful -> error
                UI_Error();
            }
            
            if (ready && (status & 0x04) > 0) { //new PDOs available
                int16_t pdo_num = I2CB_CmdRead8(AP_I2C_INST, AP_I2C_ADDR, 0x1C); //read number of available PDOs
                
                if (pdo_num <= 0) { //read fail, or none available: error
                    UI_Error();
                } else {
                    if (I2CB_CmdRead(AP_I2C_INST, AP_I2C_ADDR, 0x00, (uint8_t*)pdos, 28)) { //read pdo data
                        AP_VoltageOption* option = ap_voltage_options; //pointer to next written voltage option
                        uint8_t i, j;
                        
                        ap_voltage_option_count = 0;
                        
                        for (i = 0; i < pdo_num; i++) { //process PPS APDOs first
                            AP_APDO* apdo = &((pdos + i)->apdo);
                            if (apdo->pdoType != 0x3 || apdo->apdoType != 0x0) continue; //ignore all but PPS APDOs
                            
                            option->adjustable = true;
                            option->pdoIndex = i + 1;
                            option->minVoltagex10mV = apdo->minVoltagex100mV * 10;
                            option->maxVoltagex10mV = apdo->maxVoltagex100mV * 10;
                            option->maxCurrentx10mA = apdo->maxCurrentx50mA * 5;
                            
                            option++;
                            ap_voltage_option_count++;
                        }
                        
                        for (i = 0; i < pdo_num; i++) { //process fixed PDOs
                            AP_FPDO* fpdo = &((pdos + i)->fpdo);
                            if (fpdo->pdoType != 0x0) continue; //ignore all but fixed PDOs
                            
                            int32_t voltagex10mV = fpdo->voltageX50mV * 5;
                            
                            bool coveredByAPDO = false; //check if any PPS APDO covers fixed voltage
                            for (j = 0; j < ap_voltage_option_count; j++) {
                                AP_VoltageOption* vopt = ap_voltage_options + j;
                                if (vopt->adjustable && vopt->minVoltagex10mV <= voltagex10mV && vopt->maxVoltagex10mV >= voltagex10mV) {
                                    coveredByAPDO = true;
                                    break;
                                }
                            }
                            if (coveredByAPDO) continue; //voltage covered by PPS APDO: don't generate new option
                            
                            option->adjustable = false;
                            option->pdoIndex = i + 1;
                            option->minVoltagex10mV = voltagex10mV;
                            option->maxVoltagex10mV = voltagex10mV;
                            option->maxCurrentx10mA = fpdo->maxCurrentx10mA;
                            
                            option++;
                            ap_voltage_option_count++;
                        }
                        
                        UI_ProcessNewOptions();
                    } else { //pdo read failed: error
                        UI_Error();
                    }
                }
            }
            
            if (ui_state == UI_WAITING && ready && (status & 0x02) > 0) { //negotiation successful after wait -> output on
                ui_state = UI_OUTPUTTING;
            }
        }
    }
    
    if (util_currentTimeMicroseconds - _ap_lastMeasurement > AP_MEASURE_INTERVAL) { //periodic voltage/current measurement updates
        _ap_lastMeasurement = util_currentTimeMicroseconds;
        
        int32_t voltagex80mV = I2CB_CmdRead8(AP_I2C_INST, AP_I2C_ADDR, 0x20);
        int32_t currentx24mA = I2CB_CmdRead8(AP_I2C_INST, AP_I2C_ADDR, 0x21);
        
        if (voltagex80mV < 0 || currentx24mA < 0) {
            ui_outVoltagex10mV = -1;
            ui_outCurrentx10mA = -1;
            return;
        }
        
        ui_outVoltagex10mV = _max(voltagex80mV - 1, 0) * 8;
        ui_outCurrentx10mA = (_max(currentx24mA - 3, 0) * 24) / 10;
        
        ui_cc = ap_voltage_option_count > 0 && 
                ui_currentOption >= 0 &&
                ui_state == UI_OUTPUTTING && //CC requires outputting
                (ap_voltage_options + ui_currentOption)->adjustable && //CC requires PPS
                (ui_setVoltagex10mV - ui_outVoltagex10mV) > 30 && //CC if voltage .3V below setpoint and current within .1A of setpoint
                (ui_setCurrentx10mA - ui_outCurrentx10mA) < 10;
    }
}
