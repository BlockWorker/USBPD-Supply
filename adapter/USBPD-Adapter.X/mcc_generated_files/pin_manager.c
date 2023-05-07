/**
  PIN MANAGER Generated Driver File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.c

  @Summary:
    This is the generated manager file for the PIC24 / dsPIC33 / PIC32MM MCUs device.  This manager
    configures the pins direction, initial state, analog setting.
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Description:
    This source file provides implementations for PIN MANAGER.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.171.1
        Device            :  PIC24FJ128GA702
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.70
        MPLAB 	          :  MPLAB X v5.50
*/

/*
    (c) 2020 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/


/**
    Section: Includes
*/

#include <xc.h>
#include <stdio.h>
#include "pin_manager.h"

/**
 Section: File specific functions
*/
void (*ENC_SW_InterruptHandler)(void) = NULL;
void (*USB_INT_InterruptHandler)(void) = NULL;
void (*ENC_A_InterruptHandler)(void) = NULL;

/**
 Section: Driver Interface Function Definitions
*/
void PIN_MANAGER_Initialize (void)
{
    /****************************************************************************
     * Setting the Output Latch SFR(s)
     ***************************************************************************/
    LATA = 0x0000;
    LATB = 0x0000;

    /****************************************************************************
     * Setting the GPIO Direction SFR(s)
     ***************************************************************************/
    TRISA = 0x0017;
    TRISB = 0xFFFF;

    /****************************************************************************
     * Setting the Weak Pull Up and Weak Pull Down SFR(s)
     ***************************************************************************/
    IOCPDA = 0x0000;
    IOCPDB = 0x0000;
    IOCPUA = 0x0001;
    IOCPUB = 0xC000;

    /****************************************************************************
     * Setting the Open Drain SFR(s)
     ***************************************************************************/
    ODCA = 0x0000;
    ODCB = 0x006C;

    /****************************************************************************
     * Setting the Analog/Digital Configuration SFR(s)
     ***************************************************************************/
    ANSA = 0x0006;
    ANSB = 0x3200;
    
    /****************************************************************************
     * Interrupt On Change: positive
     ***************************************************************************/
    IOCPBbits.IOCPB15 = 1;    //Pin : RB15
    IOCPBbits.IOCPB7 = 1;    //Pin : RB7
    /****************************************************************************
     * Interrupt On Change: negative
     ***************************************************************************/
    IOCNAbits.IOCNA0 = 1;    //Pin : RA0
    /****************************************************************************
     * Interrupt On Change: flag
     ***************************************************************************/
    IOCFAbits.IOCFA0 = 0;    //Pin : RA0
    IOCFBbits.IOCFB15 = 0;    //Pin : RB15
    IOCFBbits.IOCFB7 = 0;    //Pin : RB7
    /****************************************************************************
     * Interrupt On Change: config
     ***************************************************************************/
    PADCONbits.IOCON = 1;    //Config for PORTB
    
    /* Initialize IOC Interrupt Handler*/
    ENC_SW_SetInterruptHandler(&ENC_SW_CallBack);
    USB_INT_SetInterruptHandler(&USB_INT_CallBack);
    ENC_A_SetInterruptHandler(&ENC_A_CallBack);
    
    /****************************************************************************
     * Interrupt On Change: Interrupt Enable
     ***************************************************************************/
    IFS1bits.IOCIF = 0; //Clear IOCI interrupt flag
    IEC1bits.IOCIE = 1; //Enable IOCI interrupt
}

void __attribute__ ((weak)) ENC_SW_CallBack(void)
{

}

void __attribute__ ((weak)) USB_INT_CallBack(void)
{

}

void __attribute__ ((weak)) ENC_A_CallBack(void)
{

}

void ENC_SW_SetInterruptHandler(void (* InterruptHandler)(void))
{ 
    IEC1bits.IOCIE = 0; //Disable IOCI interrupt
    ENC_SW_InterruptHandler = InterruptHandler; 
    IEC1bits.IOCIE = 1; //Enable IOCI interrupt
}

void ENC_SW_SetIOCInterruptHandler(void *handler)
{ 
    ENC_SW_SetInterruptHandler(handler);
}

void USB_INT_SetInterruptHandler(void (* InterruptHandler)(void))
{ 
    IEC1bits.IOCIE = 0; //Disable IOCI interrupt
    USB_INT_InterruptHandler = InterruptHandler; 
    IEC1bits.IOCIE = 1; //Enable IOCI interrupt
}

void USB_INT_SetIOCInterruptHandler(void *handler)
{ 
    USB_INT_SetInterruptHandler(handler);
}

void ENC_A_SetInterruptHandler(void (* InterruptHandler)(void))
{ 
    IEC1bits.IOCIE = 0; //Disable IOCI interrupt
    ENC_A_InterruptHandler = InterruptHandler; 
    IEC1bits.IOCIE = 1; //Enable IOCI interrupt
}

void ENC_A_SetIOCInterruptHandler(void *handler)
{ 
    ENC_A_SetInterruptHandler(handler);
}

/* Interrupt service routine for the IOCI interrupt. */
void __attribute__ (( interrupt, no_auto_psv )) _IOCInterrupt ( void )
{
    if(IFS1bits.IOCIF == 1)
    {
        if(IOCFAbits.IOCFA0 == 1)
        {
            if(ENC_SW_InterruptHandler) 
            { 
                ENC_SW_InterruptHandler(); 
            }
            
            IOCFAbits.IOCFA0 = 0;  //Clear flag for Pin - RA0

        }
        
        if(IOCFBbits.IOCFB7 == 1)
        {
            if(USB_INT_InterruptHandler) 
            { 
                USB_INT_InterruptHandler(); 
            }
            
            IOCFBbits.IOCFB7 = 0;  //Clear flag for Pin - RB7

        }
        
        if(IOCFBbits.IOCFB15 == 1)
        {
            if(ENC_A_InterruptHandler) 
            { 
                ENC_A_InterruptHandler(); 
            }
            
            IOCFBbits.IOCFB15 = 0;  //Clear flag for Pin - RB15

        }
        
        
        // Clear the flag
        IFS1bits.IOCIF = 0;
    }
}

