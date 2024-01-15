#ifndef UI_H
#define	UI_H

#include <xc.h>
#include "stdbool.h"


typedef enum {
    UI_IDLE,
    UI_ADJ_VOLTAGE,
    UI_ADJ_CURRENT,
    UI_ERROR,
    UI_WAITING,
    UI_OUTPUTTING
} UI_STATE;


#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    extern int8_t ui_currentOption;
    extern int32_t ui_setVoltagex10mV;
    extern int32_t ui_setCurrentx10mA;
    extern int32_t ui_outVoltagex10mV;
    extern int32_t ui_outCurrentx10mA;
    extern bool ui_pps;
    extern bool ui_cc;
    
    extern UI_STATE ui_state;
    
    void UI_Error();
    void UI_ProcessNewOptions();
    
    void UI_Initialize();
    void UI_Tasks();

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* UI_H */

