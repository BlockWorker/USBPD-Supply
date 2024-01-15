#ifndef I2C_BLOCKING_H
#define	I2C_BLOCKING_H

#include <xc.h>
#include "mcc_generated_files/i2c1.h"
#include "mcc_generated_files/i2c2.h"

typedef I2C1_MESSAGE_STATUS I2CB_MESSAGE_STATUS;
typedef I2C1_TRANSACTION_REQUEST_BLOCK I2CB_TRANSACTION_REQUEST_BLOCK;

typedef struct {
    void (*write)  (uint8_t *pdata,
                    uint8_t length,
                    uint16_t address,
                    I2CB_MESSAGE_STATUS *pstatus);
    void (*read)   (uint8_t *pdata,
                    uint8_t length,
                    uint16_t address,
                    I2CB_MESSAGE_STATUS *pstatus);
    void (*trbInsert)  (uint8_t count,
                        I2CB_TRANSACTION_REQUEST_BLOCK *ptrb_list,
                        I2CB_MESSAGE_STATUS *pflag);
    void (*readTrbBuild)   (I2CB_TRANSACTION_REQUEST_BLOCK *ptrb,
                            uint8_t *pdata,
                            uint8_t length,
                            uint16_t address);
    void (*writeTrbBuild)  (I2CB_TRANSACTION_REQUEST_BLOCK *ptrb,
                            uint8_t *pdata,
                            uint8_t length,
                            uint16_t address);
} I2CB_INSTANCE;

extern const I2CB_INSTANCE I2CB_I2C1;
extern const I2CB_INSTANCE I2CB_I2C2;

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    bool I2CB_Write(I2CB_INSTANCE instance, uint16_t address, uint8_t* data, uint8_t length);
    bool I2CB_Write8(I2CB_INSTANCE instance, uint16_t address, uint8_t data);
    bool I2CB_Write16(I2CB_INSTANCE instance, uint16_t address, uint16_t data);
    bool I2CB_Write24(I2CB_INSTANCE instance, uint16_t address, uint32_t data);
    bool I2CB_Write32(I2CB_INSTANCE instance, uint16_t address, uint32_t data);
    bool I2CB_Write40(I2CB_INSTANCE instance, uint16_t address, uint64_t data);
    
    bool I2CB_Read(I2CB_INSTANCE instance, uint16_t address, uint8_t* data, uint8_t length);
    int16_t I2CB_Read8(I2CB_INSTANCE instance, uint16_t address);
    int32_t I2CB_Read16(I2CB_INSTANCE instance, uint16_t address);
    int32_t I2CB_Read24(I2CB_INSTANCE instance, uint16_t address);
    int64_t I2CB_Read32(I2CB_INSTANCE instance, uint16_t address);
    
    bool I2CB_CmdRead(I2CB_INSTANCE instance, uint16_t address, uint8_t command, uint8_t* data, uint8_t length);
    int16_t I2CB_CmdRead8(I2CB_INSTANCE instance, uint16_t address, uint8_t command);
    int32_t I2CB_CmdRead16(I2CB_INSTANCE instance, uint16_t address, uint8_t command);
    int32_t I2CB_CmdRead24(I2CB_INSTANCE instance, uint16_t address, uint8_t command);
    int64_t I2CB_CmdRead32(I2CB_INSTANCE instance, uint16_t address, uint8_t command);
    
#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* I2C_BLOCKING_H */

