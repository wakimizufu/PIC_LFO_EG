/**
  * PWM2 Generated Driver File
  *
  * @file pwm2.c
  *
  * @ingroup pwm2
  *
  * @brief This file contains the API implementations for the PWM2 module.
  *
  * @version PWM2 Driver Version 2.0.4
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
 
 /**
  * Section: Included Files
  */

 #include <xc.h>
 #include "../pwm2.h"

 /**
  * Section: PWM Module APIs
  */

 void PWM_LFO_Initialize(void)
 {
    // Set the PWM2 to the options selected in the User Interface
    
    // PWMPOL active_hi; PWMEN enabled; 
    PWM2CON = 0x80;
    
    // PWMDCH 127; 
    PWM2DCH = 0x7F;

    // PWMDCL 3; 
    PWM2DCL = 0xC0;
    


    PWMTMRS0bits.P2TSEL = 0x1;
 }

 void PWM_LFO_LoadDutyValue(uint16_t dutyValue)
 {
     // Writing to 8 MSBs of PWM duty cycle in PWMDCH register
     PWM2DCH = (uint8_t) ((dutyValue & 0x03FCu) >> 2);
     
     // Writing to 2 LSBs of PWM duty cycle in PWMDCL register
     PWM2DCL = (uint8_t) ((dutyValue & 0x0003u) << 6);
 }
