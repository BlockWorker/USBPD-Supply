#include "sh1106_driver.h"
#include "mcc_generated_files/delay.h"
#include "i2c_blocking.h"
#include "util.h"
#include <string.h>

#define SH_I2C_ADDR 0x3C
#define SH_I2C_INST I2CB_I2C2


uint8_t sh_framebuf[SH_FRAMEBUF_SIZE] = { 0 };


static void _sh_wait_busy() {
    uint16_t status = I2CB_CmdRead8(SH_I2C_INST, SH_I2C_ADDR, 0x00);
    while (status & 0x80) {
        DELAY_milliseconds(1);
        status = I2CB_CmdRead8(SH_I2C_INST, SH_I2C_ADDR, 0x00);
    }
}

bool SH_SendCommand(uint8_t command) {
    _sh_wait_busy();
    return I2CB_Write16(SH_I2C_INST, SH_I2C_ADDR, ((uint16_t)command) << 8);
}

bool SH_SendDoubleCommand(uint8_t command1, uint8_t command2) {
    _sh_wait_busy();
    return I2CB_Write32(SH_I2C_INST, SH_I2C_ADDR, (((uint32_t)command2) << 24) | (((uint32_t)command1) << 8) | 0x80);
}

bool SH_WriteFramebuffer() {
    uint8_t buf[133] = { 0x40, 0 };
    
    //reset column address to zero
    asserttrue(SH_SendCommand(0x00));
    asserttrue(SH_SendCommand(0x10));
    
    uint16_t page;
    for (page = 0; page < 8; page++) {
        asserttrue(SH_SendCommand(0xB0 | page));
        memcpy(buf + 3, sh_framebuf + (page * 128), 128);
        _sh_wait_busy();
        asserttrue(I2CB_Write(SH_I2C_INST, SH_I2C_ADDR, buf, 133));
    }
    
    return true;
}

bool SH_Initialize() {
    asserttrue(SH_SendCommand(0xAE)); //display power off
    asserttrue(SH_SendCommand(0x32)); //pump voltage 8.0V
    asserttrue(SH_SendCommand(0x40)); //start line 0
    asserttrue(SH_SendDoubleCommand(0x81, 0x80)); //contrast 128
    asserttrue(SH_SendCommand(0xA1)); //segment remap ADC = H (flip horizontally)
    asserttrue(SH_SendCommand(0xA4)); //entire display on: disable (normal display)
    asserttrue(SH_SendCommand(0xA6)); //inverted display: disable (normal display)
    asserttrue(SH_SendDoubleCommand(0xA8, 0x3F)); //multiplex ratio 64
    asserttrue(SH_SendDoubleCommand(0xAD, 0x8B)); //DC-DC enabled (built-in)
    asserttrue(SH_SendCommand(0xC8)); //common output scan direction: reversed (flip vertically)
    asserttrue(SH_SendDoubleCommand(0xD3, 0x00)); //display offset 0
    asserttrue(SH_SendDoubleCommand(0xD5, 0x50)); //display clock frequency +-0%, divide ratio 1
    asserttrue(SH_SendDoubleCommand(0xD9, 0x22)); //discharge 2DCLK, precharge 2DCLK
    asserttrue(SH_SendDoubleCommand(0xDA, 0x12)); //common pads: alternative config
    asserttrue(SH_SendDoubleCommand(0xDB, 0x35)); //VCOM deselect level 0.770
    
    memset(sh_framebuf, 0, SH_FRAMEBUF_SIZE);
    asserttrue(SH_WriteFramebuffer());
    asserttrue(SH_SendCommand(0xAF)); //display power on
    
    return true;
}
