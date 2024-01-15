#ifndef OLED_H
#define	OLED_H

#include <xc.h>
#include <stdbool.h>


#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    bool OLED_UpdateScreen();
    bool OLED_Initialize();

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* OLED_H */

