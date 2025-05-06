/**
 * Generated Driver File
 * 
 * @file pins.c
 * 
 * @ingroup  pinsdriver
 * 
 * @brief This is generated driver implementation for pins. 
 *        This file provides implementations for pin APIs for all pins selected in the GUI.
 *
 * @version Driver Version 3.0.0
*/

/*
? [2025] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

#include "../pins.h"

void (*Gate_InterruptHandler)(void);
void (*ReTrig_InterruptHandler)(void);

void PIN_MANAGER_Initialize(void)
{
   /**
    LATx registers
    */
    LATA = 0x0;
    LATB = 0x0;
    LATC = 0x0;

    /**
    TRISx registers
    */
    TRISA = 0x27;
    TRISB = 0xA0;
    TRISC = 0xFB;

    /**
    ANSELx registers
    */
    ANSELA = 0x37;
    ANSELB = 0x90;
    ANSELC = 0xCB;

    /**
    WPUx registers
    */
    WPUA = 0x0;
    WPUB = 0x0;
    WPUC = 0x0;
  
    /**
    ODx registers
    */
   
    ODCONA = 0x0;
    ODCONB = 0x0;
    ODCONC = 0x0;
    /**
    SLRCONx registers
    */
    SLRCONA = 0x37;
    SLRCONB = 0xF0;
    SLRCONC = 0xFF;
    /**
    INLVLx registers
    */
    INLVLA = 0x2B;
    INLVLB = 0x0;
    INLVLC = 0x0;

    /**
    PPS registers
    */
    RX1PPS = 0xD; //RB5->EUSART1:RX1;
    RA4PPS = 0x2D;  //RA4->PWM2:PWM2;
    RB4PPS = 0x2C;  //RB4->PWM1:PWM1;
    RB6PPS = 0x13;  //RB6->EUSART1:TX1;

    /**
    APFCON registers
    */

   /**
    IOCx registers 
    */
    IOCAP = 0x0;
    IOCAN = 0x0;
    IOCAF = 0x0;
    IOCBP = 0x0;
    IOCBN = 0x0;
    IOCBF = 0x0;
    IOCCP = 0x30;
    IOCCN = 0x10;
    IOCCF = 0x0;

    Gate_SetInterruptHandler(Gate_DefaultInterruptHandler);
    ReTrig_SetInterruptHandler(ReTrig_DefaultInterruptHandler);

    // Enable PIE0bits.IOCIE interrupt 
    PIE0bits.IOCIE = 1; 
}
  
void PIN_MANAGER_IOC(void)
{
    // interrupt on change for pin Gate}
    if(IOCCFbits.IOCCF4 == 1)
    {
        Gate_ISR();  
    }
    // interrupt on change for pin ReTrig}
    if(IOCCFbits.IOCCF5 == 1)
    {
        ReTrig_ISR();  
    }
}
   
/**
   Gate Interrupt Service Routine
*/
void Gate_ISR(void) {

    // Add custom IOCCF4 code

    // Call the interrupt handler for the callback registered at runtime
    if(Gate_InterruptHandler)
    {
        Gate_InterruptHandler();
    }
    IOCCFbits.IOCCF4 = 0;
}

/**
  Allows selecting an interrupt handler for IOCCF4 at application runtime
*/
void Gate_SetInterruptHandler(void (* InterruptHandler)(void)){
    Gate_InterruptHandler = InterruptHandler;
}

/**
  Default interrupt handler for IOCCF4
*/
void Gate_DefaultInterruptHandler(void){
    // add your Gate interrupt custom code
    // or set custom function using Gate_SetInterruptHandler()
}
   
/**
   ReTrig Interrupt Service Routine
*/
void ReTrig_ISR(void) {

    // Add custom IOCCF5 code

    // Call the interrupt handler for the callback registered at runtime
    if(ReTrig_InterruptHandler)
    {
        ReTrig_InterruptHandler();
    }
    IOCCFbits.IOCCF5 = 0;
}

/**
  Allows selecting an interrupt handler for IOCCF5 at application runtime
*/
void ReTrig_SetInterruptHandler(void (* InterruptHandler)(void)){
    ReTrig_InterruptHandler = InterruptHandler;
}

/**
  Default interrupt handler for IOCCF5
*/
void ReTrig_DefaultInterruptHandler(void){
    // add your ReTrig interrupt custom code
    // or set custom function using ReTrig_SetInterruptHandler()
}
/**
 End of File
*/