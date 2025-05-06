/**
 * Generated Pins header File
 * 
 * @file pins.h
 * 
 * @defgroup  pinsdriver Pins Driver
 * 
 * @brief This is generated driver header for pins. 
 *        This header file provides APIs for all pins selected in the GUI.
 *
 * @version Driver Version  3.0.0
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

#ifndef PINS_H
#define PINS_H

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set IO_RA2 aliases
#define LFORate_TRIS                 TRISAbits.TRISA2
#define LFORate_LAT                  LATAbits.LATA2
#define LFORate_PORT                 PORTAbits.RA2
#define LFORate_WPU                  WPUAbits.WPUA2
#define LFORate_OD                   ODCONAbits.ODCA2
#define LFORate_ANS                  ANSELAbits.ANSA2
#define LFORate_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define LFORate_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define LFORate_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define LFORate_GetValue()           PORTAbits.RA2
#define LFORate_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define LFORate_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define LFORate_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define LFORate_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define LFORate_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define LFORate_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define LFORate_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define LFORate_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)
// get/set IO_RA4 aliases
#define IO_RA4_TRIS                 TRISAbits.TRISA4
#define IO_RA4_LAT                  LATAbits.LATA4
#define IO_RA4_PORT                 PORTAbits.RA4
#define IO_RA4_WPU                  WPUAbits.WPUA4
#define IO_RA4_OD                   ODCONAbits.ODCA4
#define IO_RA4_ANS                  ANSELAbits.ANSA4
#define IO_RA4_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define IO_RA4_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define IO_RA4_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define IO_RA4_GetValue()           PORTAbits.RA4
#define IO_RA4_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define IO_RA4_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define IO_RA4_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define IO_RA4_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define IO_RA4_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define IO_RA4_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define IO_RA4_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define IO_RA4_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)
// get/set IO_RB4 aliases
#define PWMDAC_TRIS                 TRISBbits.TRISB4
#define PWMDAC_LAT                  LATBbits.LATB4
#define PWMDAC_PORT                 PORTBbits.RB4
#define PWMDAC_WPU                  WPUBbits.WPUB4
#define PWMDAC_OD                   ODCONBbits.ODCB4
#define PWMDAC_ANS                  ANSELBbits.ANSB4
#define PWMDAC_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define PWMDAC_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define PWMDAC_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define PWMDAC_GetValue()           PORTBbits.RB4
#define PWMDAC_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define PWMDAC_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define PWMDAC_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define PWMDAC_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define PWMDAC_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define PWMDAC_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define PWMDAC_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define PWMDAC_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)
// get/set IO_RB5 aliases
#define URX1_TRIS                 TRISBbits.TRISB5
#define URX1_LAT                  LATBbits.LATB5
#define URX1_PORT                 PORTBbits.RB5
#define URX1_WPU                  WPUBbits.WPUB5
#define URX1_OD                   ODCONBbits.ODCB5
#define URX1_ANS                  ANSELBbits.ANSB5
#define URX1_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define URX1_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define URX1_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define URX1_GetValue()           PORTBbits.RB5
#define URX1_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define URX1_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define URX1_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define URX1_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define URX1_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define URX1_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define URX1_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define URX1_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)
// get/set IO_RB6 aliases
#define UTX1_TRIS                 TRISBbits.TRISB6
#define UTX1_LAT                  LATBbits.LATB6
#define UTX1_PORT                 PORTBbits.RB6
#define UTX1_WPU                  WPUBbits.WPUB6
#define UTX1_OD                   ODCONBbits.ODCB6
#define UTX1_ANS                  ANSELBbits.ANSB6
#define UTX1_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define UTX1_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define UTX1_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define UTX1_GetValue()           PORTBbits.RB6
#define UTX1_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define UTX1_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define UTX1_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define UTX1_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define UTX1_SetPushPull()        do { ODCONBbits.ODCB6 = 0; } while(0)
#define UTX1_SetOpenDrain()       do { ODCONBbits.ODCB6 = 1; } while(0)
#define UTX1_SetAnalogMode()      do { ANSELBbits.ANSB6 = 1; } while(0)
#define UTX1_SetDigitalMode()     do { ANSELBbits.ANSB6 = 0; } while(0)
// get/set IO_RB7 aliases
#define Attack_TRIS                 TRISBbits.TRISB7
#define Attack_LAT                  LATBbits.LATB7
#define Attack_PORT                 PORTBbits.RB7
#define Attack_WPU                  WPUBbits.WPUB7
#define Attack_OD                   ODCONBbits.ODCB7
#define Attack_ANS                  ANSELBbits.ANSB7
#define Attack_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define Attack_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define Attack_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define Attack_GetValue()           PORTBbits.RB7
#define Attack_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define Attack_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define Attack_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define Attack_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)
#define Attack_SetPushPull()        do { ODCONBbits.ODCB7 = 0; } while(0)
#define Attack_SetOpenDrain()       do { ODCONBbits.ODCB7 = 1; } while(0)
#define Attack_SetAnalogMode()      do { ANSELBbits.ANSB7 = 1; } while(0)
#define Attack_SetDigitalMode()     do { ANSELBbits.ANSB7 = 0; } while(0)
// get/set IO_RC0 aliases
#define LFODelay_TRIS                 TRISCbits.TRISC0
#define LFODelay_LAT                  LATCbits.LATC0
#define LFODelay_PORT                 PORTCbits.RC0
#define LFODelay_WPU                  WPUCbits.WPUC0
#define LFODelay_OD                   ODCONCbits.ODCC0
#define LFODelay_ANS                  ANSELCbits.ANSC0
#define LFODelay_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define LFODelay_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define LFODelay_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define LFODelay_GetValue()           PORTCbits.RC0
#define LFODelay_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define LFODelay_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define LFODelay_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define LFODelay_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define LFODelay_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define LFODelay_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define LFODelay_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define LFODelay_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)
// get/set IO_RC1 aliases
#define LFOWave_TRIS                 TRISCbits.TRISC1
#define LFOWave_LAT                  LATCbits.LATC1
#define LFOWave_PORT                 PORTCbits.RC1
#define LFOWave_WPU                  WPUCbits.WPUC1
#define LFOWave_OD                   ODCONCbits.ODCC1
#define LFOWave_ANS                  ANSELCbits.ANSC1
#define LFOWave_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define LFOWave_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define LFOWave_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define LFOWave_GetValue()           PORTCbits.RC1
#define LFOWave_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define LFOWave_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define LFOWave_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define LFOWave_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define LFOWave_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define LFOWave_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define LFOWave_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define LFOWave_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)
// get/set IO_RC2 aliases
#define TP_TRIS                 TRISCbits.TRISC2
#define TP_LAT                  LATCbits.LATC2
#define TP_PORT                 PORTCbits.RC2
#define TP_WPU                  WPUCbits.WPUC2
#define TP_OD                   ODCONCbits.ODCC2
#define TP_ANS                  ANSELCbits.ANSC2
#define TP_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define TP_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define TP_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define TP_GetValue()           PORTCbits.RC2
#define TP_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define TP_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define TP_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define TP_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define TP_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define TP_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define TP_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define TP_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)
// get/set IO_RC3 aliases
#define Decay_TRIS                 TRISCbits.TRISC3
#define Decay_LAT                  LATCbits.LATC3
#define Decay_PORT                 PORTCbits.RC3
#define Decay_WPU                  WPUCbits.WPUC3
#define Decay_OD                   ODCONCbits.ODCC3
#define Decay_ANS                  ANSELCbits.ANSC3
#define Decay_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define Decay_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define Decay_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define Decay_GetValue()           PORTCbits.RC3
#define Decay_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define Decay_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define Decay_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define Decay_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define Decay_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define Decay_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define Decay_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define Decay_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)
// get/set IO_RC4 aliases
#define Gate_TRIS                 TRISCbits.TRISC4
#define Gate_LAT                  LATCbits.LATC4
#define Gate_PORT                 PORTCbits.RC4
#define Gate_WPU                  WPUCbits.WPUC4
#define Gate_OD                   ODCONCbits.ODCC4
#define Gate_ANS                  ANSELCbits.ANSC4
#define Gate_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define Gate_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define Gate_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define Gate_GetValue()           PORTCbits.RC4
#define Gate_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define Gate_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define Gate_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define Gate_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define Gate_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define Gate_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define Gate_SetAnalogMode()      do { ANSELCbits.ANSC4 = 1; } while(0)
#define Gate_SetDigitalMode()     do { ANSELCbits.ANSC4 = 0; } while(0)
#define RC4_SetInterruptHandler  Gate_SetInterruptHandler
// get/set IO_RC5 aliases
#define ReTrig_TRIS                 TRISCbits.TRISC5
#define ReTrig_LAT                  LATCbits.LATC5
#define ReTrig_PORT                 PORTCbits.RC5
#define ReTrig_WPU                  WPUCbits.WPUC5
#define ReTrig_OD                   ODCONCbits.ODCC5
#define ReTrig_ANS                  ANSELCbits.ANSC5
#define ReTrig_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define ReTrig_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define ReTrig_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define ReTrig_GetValue()           PORTCbits.RC5
#define ReTrig_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define ReTrig_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define ReTrig_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define ReTrig_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define ReTrig_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define ReTrig_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define ReTrig_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define ReTrig_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)
#define RC5_SetInterruptHandler  ReTrig_SetInterruptHandler
// get/set IO_RC6 aliases
#define Sustain_TRIS                 TRISCbits.TRISC6
#define Sustain_LAT                  LATCbits.LATC6
#define Sustain_PORT                 PORTCbits.RC6
#define Sustain_WPU                  WPUCbits.WPUC6
#define Sustain_OD                   ODCONCbits.ODCC6
#define Sustain_ANS                  ANSELCbits.ANSC6
#define Sustain_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define Sustain_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define Sustain_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define Sustain_GetValue()           PORTCbits.RC6
#define Sustain_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define Sustain_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define Sustain_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define Sustain_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define Sustain_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define Sustain_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define Sustain_SetAnalogMode()      do { ANSELCbits.ANSC6 = 1; } while(0)
#define Sustain_SetDigitalMode()     do { ANSELCbits.ANSC6 = 0; } while(0)
// get/set IO_RC7 aliases
#define Release_TRIS                 TRISCbits.TRISC7
#define Release_LAT                  LATCbits.LATC7
#define Release_PORT                 PORTCbits.RC7
#define Release_WPU                  WPUCbits.WPUC7
#define Release_OD                   ODCONCbits.ODCC7
#define Release_ANS                  ANSELCbits.ANSC7
#define Release_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define Release_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define Release_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define Release_GetValue()           PORTCbits.RC7
#define Release_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define Release_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define Release_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define Release_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define Release_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define Release_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define Release_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define Release_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)
/**
 * @ingroup  pinsdriver
 * @brief GPIO and peripheral I/O initialization
 * @param none
 * @return none
 */
void PIN_MANAGER_Initialize (void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handling routine
 * @param none
 * @return none
 */
void PIN_MANAGER_IOC(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handler for the Gate pin functionality
 * @param none
 * @return none
 */
void Gate_ISR(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for Gate pin interrupt-on-change functionality.
 *        Allows selecting an interrupt handler for Gate at application runtime.
 * @pre Pins intializer called
 * @param InterruptHandler function pointer.
 * @return none
 */
void Gate_SetInterruptHandler(void (* InterruptHandler)(void));

/**
 * @ingroup  pinsdriver
 * @brief Dynamic Interrupt Handler for Gate pin.
 *        This is a dynamic interrupt handler to be used together with the Gate_SetInterruptHandler() method.
 *        This handler is called every time the Gate ISR is executed and allows any function to be registered at runtime.
 * @pre Pins intializer called
 * @param none
 * @return none
 */
extern void (*Gate_InterruptHandler)(void);

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for Gate pin. 
 *        This is a predefined interrupt handler to be used together with the Gate_SetInterruptHandler() method.
 *        This handler is called every time the Gate ISR is executed. 
 * @pre Pins intializer called
 * @param none
 * @return none
 */
void Gate_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handler for the ReTrig pin functionality
 * @param none
 * @return none
 */
void ReTrig_ISR(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for ReTrig pin interrupt-on-change functionality.
 *        Allows selecting an interrupt handler for ReTrig at application runtime.
 * @pre Pins intializer called
 * @param InterruptHandler function pointer.
 * @return none
 */
void ReTrig_SetInterruptHandler(void (* InterruptHandler)(void));

/**
 * @ingroup  pinsdriver
 * @brief Dynamic Interrupt Handler for ReTrig pin.
 *        This is a dynamic interrupt handler to be used together with the ReTrig_SetInterruptHandler() method.
 *        This handler is called every time the ReTrig ISR is executed and allows any function to be registered at runtime.
 * @pre Pins intializer called
 * @param none
 * @return none
 */
extern void (*ReTrig_InterruptHandler)(void);

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for ReTrig pin. 
 *        This is a predefined interrupt handler to be used together with the ReTrig_SetInterruptHandler() method.
 *        This handler is called every time the ReTrig ISR is executed. 
 * @pre Pins intializer called
 * @param none
 * @return none
 */
void ReTrig_DefaultInterruptHandler(void);


#endif // PINS_H
/**
 End of File
*/