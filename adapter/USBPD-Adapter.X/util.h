#ifndef UTIL_H
#define	UTIL_H

#include <xc.h>

#define asserttrue(c) do { if (!(c)) return false; } while(0)
#define _max(a,b) (((a) >= (b)) ? (a) : (b))
#define _min(a,b) (((a) <= (b)) ? (a) : (b))

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    extern uint64_t util_currentTimeMicroseconds;
    
    uint64_t UTIL_GetTimeMicroseconds();
    void UTIL_UpdateCurrentTime();

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* UTIL_H */

