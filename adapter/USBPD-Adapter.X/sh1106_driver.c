#include "sh1106_driver.h"
#include "mcc_generated_files/delay.h"
#include "i2c_blocking.h"
#include <string.h>

#define SH_I2C_ADDR 0x3C
#define SH_I2C_INST I2CB_I2C2
#define SH_FRAMEBUF_SIZE 1024

static uint8_t _sh_framebuf[SH_FRAMEBUF_SIZE] = { 0 };


static void _sh_wait_busy() {
    uint16_t status = I2CB_CmdRead8(SH_I2C_INST, SH_I2C_ADDR, 0x00);
    while (status & 0x80) {
        DELAY_milliseconds(1);
        status = I2CB_CmdRead8(SH_I2C_INST, SH_I2C_ADDR, 0x00);
    }
}

static void _sh_write_framebuf_full() {
    uint8_t buf[133] = { 0x40, 0 };
    
    uint16_t page;
    for (page = 0; page < 8; page++) {
        _sh_wait_busy();
        I2CB_Write16(SH_I2C_INST, SH_I2C_ADDR, 0xB000 | (page << 8));
        memcpy(buf + 3, _sh_framebuf + (page * 128), 128);
        _sh_wait_busy();
        I2CB_Write(SH_I2C_INST, SH_I2C_ADDR, buf, 133);
    }
}

void SH_Initialize() {
    _sh_wait_busy();
    I2CB_Write16(SH_I2C_INST, SH_I2C_ADDR, 0xAE00); //display power off
    _sh_wait_busy();
    I2CB_Write16(SH_I2C_INST, SH_I2C_ADDR, 0xA400); //normal display (not all on)
    _sh_wait_busy();
    I2CB_Write16(SH_I2C_INST, SH_I2C_ADDR, 0xC800); //flip vertically
    _sh_wait_busy();
    I2CB_Write16(SH_I2C_INST, SH_I2C_ADDR, 0xA100); //flip horizontally
    _sh_framebuf[0] = 0x11;
    _sh_framebuf[127] = 0xAA;
    _sh_framebuf[128] = 0x55;
    _sh_framebuf[129] = 0xAA;
    _sh_write_framebuf_full();
    _sh_wait_busy();
    I2CB_Write16(SH_I2C_INST, SH_I2C_ADDR, 0xAF00); //display power on
}
