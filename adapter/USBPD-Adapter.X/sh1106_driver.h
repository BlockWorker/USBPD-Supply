#ifndef SH1106_DRIVER_H
#define	SH1106_DRIVER_H

#include <xc.h> 
#include <stdbool.h>


#define SH_FRAMEBUF_SIZE 1024


#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */
    
    extern uint8_t sh_framebuf[SH_FRAMEBUF_SIZE];
    
    bool SH_SendCommand(uint8_t command);
    bool SH_SendDoubleCommand(uint8_t command1, uint8_t command2);
    bool SH_WriteFramebuffer();
    bool SH_Initialize();

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* SH1106_DRIVER_H */

