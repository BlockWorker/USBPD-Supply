#include "ui.h"
#include "mcc_generated_files/pin_manager.h"
#include "util.h"
#include "ap33772.h"


#define UI_ENCODER_DEBOUNCE_TIME 5000
#define UI_ENCODER_FAST_THRESH 100000
#define UI_BUTTON_DEBOUNCE_TIME 10000
#define UI_BUTTON_LONGPRESS_THRESH 1000000


int8_t ui_currentOption = -1;
int32_t ui_setVoltagex10mV = -1;
int32_t ui_setCurrentx10mA = -1;
int32_t ui_outVoltagex10mV = 0;
int32_t ui_outCurrentx10mA = 0;
bool ui_pps = false;
bool ui_cc = false;

static int8_t _ui_encoderInput = 0;
static uint64_t _ui_encoderDebounceStart = 0;
static bool _ui_buttonPressed = false;
static bool _ui_buttonDebouncing = false;
static uint64_t _ui_buttonDebounceStart = 0;

static uint64_t _ui_lastEncChangeAt = 0;
static uint64_t _ui_buttonPressedAt = 0;
static bool _ui_longPressDone = false;

UI_STATE ui_state = UI_IDLE;


void _ui_encoderCallback() {
    uint64_t time = UTIL_GetTimeMicroseconds();
    
    if (time - _ui_encoderDebounceStart < UI_ENCODER_DEBOUNCE_TIME) return;
    
    uint16_t portb = PORTB;
    bool enc_a = (portb & 0x8000) > 0;
    bool enc_b = (portb & 0x4000) > 0;
    
    if (enc_a == enc_b) _ui_encoderInput--;
    else _ui_encoderInput++;
    
    _ui_encoderDebounceStart = time;
}

void _ui_buttonCallback() {    
    if (!_ui_buttonDebouncing) {
        _ui_buttonDebouncing = true;
        _ui_buttonDebounceStart = UTIL_GetTimeMicroseconds();
    }
}

static void _ui_handleEncoderChange(int8_t change) {
    bool largeStep = (util_currentTimeMicroseconds - _ui_lastEncChangeAt) < (UI_ENCODER_FAST_THRESH * (change < 0 ? -change : change));
    _ui_lastEncChangeAt = util_currentTimeMicroseconds;
    
    AP_VoltageOption* option = ap_voltage_options + ui_currentOption;
    int32_t desired_setting;
    
    switch (ui_state) {
        case UI_ADJ_VOLTAGE:
            desired_setting = ui_setVoltagex10mV + (int32_t)change * (largeStep ? 10 : 2);
            
            if (option->adjustable) { //try to adjust current option first, break out of switch if successful
                if (change < 0 && ui_setVoltagex10mV > option->minVoltagex10mV) {
                    ui_setVoltagex10mV = _max(desired_setting, option->minVoltagex10mV);
                    break;
                } else if (change > 0 && ui_setVoltagex10mV < option->maxVoltagex10mV) {
                    ui_setVoltagex10mV = _min(desired_setting, option->maxVoltagex10mV);
                    break;
                }
            }
            
            //find nearest option which would allow a change in the desired direction
            int i;
            int8_t next_closest_opt = ui_currentOption;
            int32_t next_closest_val;
            AP_VoltageOption* next_option;
            if (change < 0) { //decrease: find highest minimum that is below current minimum
                next_closest_val = 0;
                for (i = 0; i < ap_voltage_option_count; i++) {
                    next_option = ap_voltage_options + i;
                    if (next_option->minVoltagex10mV < option->minVoltagex10mV && next_option->minVoltagex10mV > next_closest_val) {
                        next_closest_opt = i;
                        next_closest_val = next_option->minVoltagex10mV;
                    }
                }
            } else { //increase: find lowest maximum that is above current maximum
                next_closest_val = 2100;
                for (i = 0; i < ap_voltage_option_count; i++) {
                    next_option = ap_voltage_options + i;
                    if (next_option->maxVoltagex10mV > option->maxVoltagex10mV && next_option->maxVoltagex10mV < next_closest_val) {
                        next_closest_opt = i;
                        next_closest_val = next_option->maxVoltagex10mV;
                    }
                }
            }
            if (next_closest_opt != ui_currentOption) { //if new option found: switch to it and set voltage accordingly
                ui_currentOption = next_closest_opt;
                option = ap_voltage_options + ui_currentOption;
                ui_setVoltagex10mV = _min(_max(desired_setting, option->minVoltagex10mV), option->maxVoltagex10mV);
                ui_setCurrentx10mA = option->maxCurrentx10mA;
                ui_pps = option->adjustable;
            }
            
            break;
        case UI_ADJ_CURRENT:
            if (!option->adjustable) break;
            desired_setting = ui_setCurrentx10mA + (int32_t)change * 5;
            ui_setCurrentx10mA = _min(_max(desired_setting, 100), option->maxCurrentx10mA);
            break;
        default:
            break;
    }
}

static void _ui_handleShortPress() {
    switch (ui_state) {
        case UI_IDLE:
            if (ui_currentOption < 0 && ap_voltage_option_count > 0) {
                ui_currentOption = 0;
                ui_setVoltagex10mV = ap_voltage_options->minVoltagex10mV;
                ui_setCurrentx10mA = ap_voltage_options->maxCurrentx10mA;
                ui_pps = ap_voltage_options->adjustable;
            }
            
            ui_state = UI_ADJ_VOLTAGE;
            break;
        case UI_ADJ_VOLTAGE:
            if (ui_currentOption >= 0 && (ap_voltage_options + ui_currentOption)->adjustable) {
                ui_state = UI_ADJ_CURRENT;
            } else {
                ui_state = UI_IDLE;
            }
            break;
        case UI_OUTPUTTING:
            AP_Reset();
        case UI_ERROR:
        case UI_ADJ_CURRENT:
            ui_state = UI_IDLE;
            break;
        case UI_WAITING:
        default:
            break;
    }
}

static void _ui_handleLongPress() {
    if (ui_state != UI_IDLE) {
        _ui_handleShortPress();
        return;
    }
    
    if (ui_currentOption < 0 || ui_setVoltagex10mV < 0 || ui_setCurrentx10mA < 0) return;
    
    ui_state = UI_WAITING;
    if (!AP_SendRDO(ui_currentOption, ui_setVoltagex10mV, ui_setCurrentx10mA)) UI_Error();
}


void UI_Error() {
    AP_Reset();
    ui_state = UI_ERROR;
    ui_currentOption = -1;
    ui_setVoltagex10mV = -1;
    ui_setCurrentx10mA = -1;
    ui_pps = false;
    ui_cc = false;
}

void UI_ProcessNewOptions() {
    switch (ui_state) {
        case UI_ADJ_VOLTAGE:
        case UI_ADJ_CURRENT:
        case UI_WAITING:
            ui_state = UI_IDLE;
        case UI_IDLE:
        case UI_OUTPUTTING:
            if (ui_currentOption < 0 || ui_setVoltagex10mV < 0 || ui_setCurrentx10mA < 0) break;
            uint8_t i;
            bool found = false;
            for (i = 0; i < ap_voltage_option_count; i++) { //check all new options for a fitting one for current settings
                AP_VoltageOption* option = ap_voltage_options + i;
                if (option->minVoltagex10mV <= ui_setVoltagex10mV && option->maxVoltagex10mV >= ui_setVoltagex10mV) {
                    if (option->adjustable && ui_setCurrentx10mA < 100) continue; //don't support PPS with <1A current
                    
                    ui_currentOption = i;
                    if (option->maxCurrentx10mA < ui_setCurrentx10mA) ui_setCurrentx10mA = option->maxCurrentx10mA; //limit current to new max
                    ui_pps = option->adjustable;
                    
                    if (ui_state == UI_OUTPUTTING) { //adjust to new option if outputting
                        ui_state = UI_WAITING;
                        if (!AP_SendRDO(ui_currentOption, ui_setVoltagex10mV, ui_setCurrentx10mA)) break;
                    }
                    
                    found = true;
                    break;
                }
            }
            if (!found) { //no fitting option found for current settings: error and reset
                UI_Error();
            }
            break;
        case UI_ERROR:
        default:
            break;
    }
}

void UI_Initialize() {
    ui_currentOption = -1;
    ui_setVoltagex10mV = -1;
    ui_setCurrentx10mA = -1;
    ui_outVoltagex10mV = 0;
    ui_outCurrentx10mA = 0;
    ui_pps = false;
    ui_cc = false;
    
    _ui_encoderInput = 0;
    _ui_encoderDebounceStart = 0;
    _ui_buttonPressed = false;
    _ui_buttonDebouncing = false;
    _ui_buttonDebounceStart = 0;
    
    _ui_lastEncChangeAt = 0;
    _ui_buttonPressedAt = 0;
    _ui_longPressDone = false;
    
    ui_state = UI_IDLE;
    
    ENC_A_SetInterruptHandler(&_ui_encoderCallback);
    ENC_SW_SetInterruptHandler(&_ui_buttonCallback);
}

void UI_Tasks() {
    if (_ui_buttonDebouncing) {
        if (util_currentTimeMicroseconds - _ui_buttonDebounceStart >= UI_BUTTON_DEBOUNCE_TIME) {
            _ui_buttonPressed = !ENC_SW_GetValue();
            _ui_buttonDebouncing = false;
            
            if (_ui_buttonPressed) {
                _ui_buttonPressedAt = util_currentTimeMicroseconds;
            } else {
                if (!_ui_longPressDone) {
                    _ui_handleShortPress();
                }
                _ui_longPressDone = false;
            }
        }
    }
    
    if (_ui_buttonPressed && !_ui_longPressDone) {
        if (util_currentTimeMicroseconds - _ui_buttonDebounceStart >= UI_BUTTON_LONGPRESS_THRESH) {
            _ui_longPressDone = true;
            _ui_handleLongPress();
        }
    }
    
    if (_ui_encoderInput != 0 && !_ui_buttonPressed && !_ui_buttonDebouncing) {
        _ui_handleEncoderChange(_ui_encoderInput);
    }
    
    _ui_encoderInput = 0;
}
