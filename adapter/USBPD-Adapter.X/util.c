#include "util.h"
#include "mcc_generated_files/tmr2.h"


uint64_t util_currentTimeMicroseconds = 0;


uint64_t UTIL_GetTimeMicroseconds() {
    __builtin_disable_interrupts();
    uint64_t upper = TMR2_SoftwareCounterGet();
    uint64_t lower = TMR2_Counter32BitGet();
    __builtin_enable_interrupts();
    
    return (upper << 32) | lower;
}

void UTIL_UpdateCurrentTime() {
    util_currentTimeMicroseconds = UTIL_GetTimeMicroseconds();
}
