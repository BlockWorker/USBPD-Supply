#include "i2c_blocking.h"
#include "mcc_generated_files/delay.h"

#define _I2CB_RETRY_MAX       10  // define the retry count
#define _I2CB_DEVICE_TIMEOUT  50   // define slave timeout


const I2CB_INSTANCE I2CB_I2C1 = {
    &I2C1_MasterWrite,
    &I2C1_MasterRead,
    &I2C1_MasterTRBInsert,
    &I2C1_MasterReadTRBBuild,
    &I2C1_MasterWriteTRBBuild
};

const I2CB_INSTANCE I2CB_I2C2 = {
    &I2C2_MasterWrite,
    &I2C2_MasterRead,
    &I2C2_MasterTRBInsert,
    &I2C2_MasterReadTRBBuild,
    &I2C2_MasterWriteTRBBuild
};


bool I2CB_Write(I2CB_INSTANCE instance, uint16_t address, uint8_t* data, uint8_t length) {
    I2CB_MESSAGE_STATUS status = I2C1_MESSAGE_PENDING;
    uint16_t retryTimeOut, slaveTimeOut;
    
    retryTimeOut = 0;
    slaveTimeOut = 0;

    while (status != I2C1_MESSAGE_FAIL) {
        instance.write(data, length, address, &status);

        while(status == I2C1_MESSAGE_PENDING) {
            DELAY_microseconds(500);
            
            if (slaveTimeOut == _I2CB_DEVICE_TIMEOUT) return false;
            else slaveTimeOut++;
        }

        if (status == I2C1_MESSAGE_COMPLETE) break;

        if (retryTimeOut == _I2CB_RETRY_MAX) break;
        else retryTimeOut++;
    }

    return status == I2C1_MESSAGE_COMPLETE;
}

bool I2CB_Write8(I2CB_INSTANCE instance, uint16_t address, uint8_t data) {
    return I2CB_Write(instance, address, &data, 1);
}

bool I2CB_Write16(I2CB_INSTANCE instance, uint16_t address, uint16_t data) {
    return I2CB_Write(instance, address, (uint8_t*)&data, 2);
}

bool I2CB_Write24(I2CB_INSTANCE instance, uint16_t address, uint32_t data) {
    return I2CB_Write(instance, address, (uint8_t*)&data, 3);
}

bool I2CB_Write32(I2CB_INSTANCE instance, uint16_t address, uint32_t data) {
    return I2CB_Write(instance, address, (uint8_t*)&data, 4);
}

bool I2CB_Write40(I2CB_INSTANCE instance, uint16_t address, uint64_t data) {
    return I2CB_Write(instance, address, (uint8_t*)&data, 5);
}


bool I2CB_Read(I2CB_INSTANCE instance, uint16_t address, uint8_t* data, uint8_t length) {
    I2CB_MESSAGE_STATUS status = I2C1_MESSAGE_PENDING;
    uint16_t retryTimeOut, slaveTimeOut;
    
    retryTimeOut = 0;
    slaveTimeOut = 0;

    while (status != I2C1_MESSAGE_FAIL) {
        instance.read(data, length, address, &status);

        while(status == I2C1_MESSAGE_PENDING) {
            DELAY_microseconds(500);
            
            if (slaveTimeOut == _I2CB_DEVICE_TIMEOUT) return false;
            else slaveTimeOut++;
        }

        if (status == I2C1_MESSAGE_COMPLETE) break;

        if (retryTimeOut == _I2CB_RETRY_MAX) break;
        else retryTimeOut++;
    }

    return status == I2C1_MESSAGE_COMPLETE;
}

int16_t I2CB_Read8(I2CB_INSTANCE instance, uint16_t address) {
    int16_t res = 0;
    if (!I2CB_Read(instance, address, (uint8_t*)&res, 1)) res = -1;
    return res;
}

int32_t I2CB_Read16(I2CB_INSTANCE instance, uint16_t address) {
    int32_t res = 0;
    if (!I2CB_Read(instance, address, (uint8_t*)&res, 2)) res = -1;
    return res;
}

int32_t I2CB_Read24(I2CB_INSTANCE instance, uint16_t address) {
    int32_t res = 0;
    if (!I2CB_Read(instance, address, (uint8_t*)&res, 3)) res = -1;
    return res;
}

int64_t I2CB_Read32(I2CB_INSTANCE instance, uint16_t address) {
    int64_t res = 0;
    if (!I2CB_Read(instance, address, (uint8_t*)&res, 4)) res = -1;
    return res;
}

bool I2CB_CmdRead(I2CB_INSTANCE instance, uint16_t address, uint8_t command, uint8_t* data, uint8_t length) {
    I2CB_MESSAGE_STATUS status = I2C1_MESSAGE_PENDING;
    I2CB_TRANSACTION_REQUEST_BLOCK trb[2];
    uint16_t retryTimeOut, slaveTimeOut;
    
    retryTimeOut = 0;
    slaveTimeOut = 0;
    
    instance.writeTrbBuild(trb, &command, 1, address);
    instance.readTrbBuild(trb + 1, data, length, address);

    while (status != I2C1_MESSAGE_FAIL) {
        instance.trbInsert(2, trb, &status);

        while(status == I2C1_MESSAGE_PENDING) {
            DELAY_microseconds(500);
            
            if (slaveTimeOut == _I2CB_DEVICE_TIMEOUT) return false;
            else slaveTimeOut++;
        }

        if (status == I2C1_MESSAGE_COMPLETE) break;

        if (retryTimeOut == _I2CB_RETRY_MAX) break;
        else retryTimeOut++;
    }

    return status == I2C1_MESSAGE_COMPLETE;
}

int16_t I2CB_CmdRead8(I2CB_INSTANCE instance, uint16_t address, uint8_t command) {
    int16_t res = 0;
    if (!I2CB_CmdRead(instance, address, command, (uint8_t*)&res, 1)) res = -1;
    return res;
}

int32_t I2CB_CmdRead16(I2CB_INSTANCE instance, uint16_t address, uint8_t command) {
    int32_t res = 0;
    if (!I2CB_CmdRead(instance, address, command, (uint8_t*)&res, 2)) res = -1;
    return res;
}

int32_t I2CB_CmdRead24(I2CB_INSTANCE instance, uint16_t address, uint8_t command) {
    int32_t res = 0;
    if (!I2CB_CmdRead(instance, address, command, (uint8_t*)&res, 3)) res = -1;
    return res;
}

int64_t I2CB_CmdRead32(I2CB_INSTANCE instance, uint16_t address, uint8_t command) {
    int64_t res = 0;
    if (!I2CB_CmdRead(instance, address, command, (uint8_t*)&res, 4)) res = -1;
    return res;
}

