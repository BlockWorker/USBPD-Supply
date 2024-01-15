#ifndef AP33772_H
#define	AP33772_H

#include <xc.h> 
#include <stdbool.h>


typedef struct {
    unsigned int __attribute__((packed)) maxCurrentx10mA : 10;
    unsigned int __attribute__((packed)) voltageX50mV : 10;
    unsigned int __attribute__((packed)) : 10;
    unsigned int __attribute__((packed)) pdoType : 2;
} AP_FPDO;

typedef struct {
    unsigned int __attribute__((packed)) maxCurrentx50mA : 7;
    unsigned int __attribute__((packed)) : 1;
    unsigned int __attribute__((packed)) minVoltagex100mV : 8;
    unsigned int __attribute__((packed)) : 1;
    unsigned int __attribute__((packed)) maxVoltagex100mV : 8;
    unsigned int __attribute__((packed)) : 3;
    unsigned int __attribute__((packed)) apdoType : 2;
    unsigned int __attribute__((packed)) pdoType : 2;
} AP_APDO;

typedef union {
    AP_FPDO fpdo;
    AP_APDO apdo;
} AP_PDO;

typedef struct {
    unsigned int __attribute__((packed)) maxCurrentx10mA : 10;
    unsigned int __attribute__((packed)) minCurrentx10mA : 10;
    unsigned int __attribute__((packed)) : 8;
    unsigned int __attribute__((packed)) pdoIndex : 3;
    unsigned int __attribute__((packed)) : 1;
} AP_FRDO;

typedef struct {
    unsigned int __attribute__((packed)) currentx50mA : 7;
    unsigned int __attribute__((packed)) : 2;
    unsigned int __attribute__((packed)) voltagex20mV : 11;
    unsigned int __attribute__((packed)) : 8;
    unsigned int __attribute__((packed)) pdoIndex : 3;
    unsigned int __attribute__((packed)) : 1;
} AP_PRDO;

typedef union {
    AP_FRDO frdo;
    AP_PRDO prdo;
} AP_RDO;

typedef struct {
    bool adjustable;
    uint8_t pdoIndex;
    int32_t minVoltagex10mV;
    int32_t maxVoltagex10mV;
    int32_t maxCurrentx10mA;
} AP_VoltageOption;

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */
    
    extern AP_VoltageOption ap_voltage_options[7];
    extern uint8_t ap_voltage_option_count;
    
    
    bool AP_Reset();
    bool AP_SendRDO(uint8_t option, int32_t voltagex10mV, int32_t currentx10mA);
    
    bool AP_Initialize();
    void AP_Tasks();

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* AP33772_H */

