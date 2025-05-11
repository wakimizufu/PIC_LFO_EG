 /*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.2
 *
 * @version Package Version: 3.1.2
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
#include "mcc_generated_files/system/system.h"
#include <stdbool.h>
#include <math.h>

/*
    Main application
*/

//変数
_Bool onTMR1; 

const unsigned int sineTbl[256] = {
640,646,652,658,664,672,678,684,690,696,702,708,714,720,726,732,738,742,
748,754,760,766,770,776,782,786,792,796,802,806,810,816,820,824,828,832,
836,840,844,848,852,854,858,860,864,866,870,872,874,876,880,882,884,884,
886,888,890,890,892,892,892,894,894,894,894,894,894,894,892,892,892,890,
890,888,886,884,884,882,880,876,874,872,870,866,864,860,858,854,852,848,
844,840,836,832,828,824,820,816,810,806,802,796,792,786,782,776,770,766,
760,754,748,742,738,732,726,720,714,708,702,696,690,684,678,672,664,658,
652,646,640,634,628,622,616,608,602,596,590,584,578,572,566,560,554,548,
542,538,532,526,520,514,510,504,498,494,488,484,478,474,470,464,460,456,
452,448,444,440,436,432,428,426,422,420,416,414,410,408,406,404,400,398,
396,396,394,392,390,390,388,388,388,386,386,386,386,386,386,386,388,388,
388,390,390,392,394,396,396,398,400,404,406,408,410,414,416,420,422,426,
428,432,436,440,444,448,452,456,460,464,470,474,478,484,488,494,498,504,
510,514,520,526,532,538,542,548,554,560,566,572,578,584,590,596,602,608,616,622,628,634};



// 関数プロトタイプ
void MyTMR1_ISR(void);

// ユーザーの割り込み関数
void MyTMR1_ISR(void){
    onTMR1 = true;
}

int main(void)
{
    
    __uint24 accmulator = 0;
	unsigned int clock = 4000;	
	unsigned int fout = 10;
    double tuningWord = 0x01000000 * fout / clock;    //double tuningWord = (pow(2, 32) * fout) / clock;
    //tuningWord=tuningWord*0.5;
    
    SYSTEM_Initialize();

    onTMR1 = false;

     TMR1_OverflowCallbackRegister(MyTMR1_ISR);
    TMR1_Start();
    
    // Enable the Global Interrupts 
    INTERRUPT_GlobalInterruptEnable(); 

    // Enable the Peripheral Interrupts 
    INTERRUPT_PeripheralInterruptEnable(); 

    __uint24 count;
	unsigned int dacval;           
           
    while(1)
    {
        if (onTMR1){
            
            count = accmulator >> 16;
            dacval = sineTbl[count];
            PWM_LFO_LoadDutyValue(dacval);

            accmulator += tuningWord;
            onTMR1 = false;
        }
    }    
}