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

/*
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
*/

const unsigned int sineTbl[256] = {
358,366,375,383,392,403,411,420,428,436,445,453,462,470,478,487,495,501,
509,518,526,534,540,548,557,562,571,576,585,590,596,604,610,616,621,627,
632,638,644,649,655,658,663,666,672,674,680,683,686,688,694,697,700,700,
702,705,708,708,711,711,711,714,714,714,714,714,714,714,711,711,711,708,
708,705,702,700,700,697,694,688,686,683,680,674,672,666,663,658,655,649,
644,638,632,627,621,616,610,604,596,590,585,576,571,562,557,548,540,534,
526,518,509,501,495,487,478,470,462,453,445,436,428,420,411,403,392,383,
375,366,358,350,341,333,324,313,305,296,288,280,271,263,254,246,238,229,
221,215,207,198,190,182,176,168,159,154,145,140,131,126,120,112,106,100,
95,89,84,78,72,67,61,58,53,50,44,42,36,33,30,28,22,19,
16,16,14,11,8,8,5,5,5,2,2,2,2,2,2,2,5,5,
5,8,8,11,14,16,16,19,22,28,30,33,36,42,44,50,53,58,
61,67,72,78,84,89,95,100,106,112,120,126,131,140,145,154,159,168,
176,182,190,198,207,215,221,229,238,246,254,263,271,280,288,296,305,313,324,333,341,350};

//ADC変換タイミング(単位:2msec)
#define ADC_CONVERT_TIME 100 

//ADC 8bitに対するLFOステップ周波数(単位:Hz))
#define LFO_STEP_TIME 0.117 

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
	double fout = 10;
    double tuningWord = 0x01000000 * fout / clock;    //double tuningWord = (pow(2, 32) * fout) / clock;
    
    SYSTEM_Initialize();

    onTMR1 = false;

     TMR1_OverflowCallbackRegister(MyTMR1_ISR);
    TMR1_Start();
    
    // Enable the Global Interrupts  
    INTERRUPT_GlobalInterruptEnable(); 

    // Enable the Peripheral Interrupts 
    INTERRUPT_PeripheralInterruptEnable(); 

    unsigned int onLFORate = ADC_CONVERT_TIME;
    ADC_ChannelSelect(LFORATE); //ADC_CHANNEL_ANA2
    ADC_ConversionStart();
    
    __uint24 count;
	unsigned int dacval;           
           
    while(1)
    {
        if (onTMR1){
            
            count = accmulator >> 16;
            dacval = sineTbl[count];
            PWM_LFO_LoadDutyValue(dacval);

            //PWM_LFO_LoadDutyValue(ADC_ConversionResultGet());
            
            accmulator += tuningWord;
   
            onLFORate--;            
            onTMR1 = false;
        }
        
        if (0 == onLFORate){
           ADC_ConversionStart();
           while(!ADC_IsConversionDone());
            
           fout = ( (ADC_ConversionResultGet()>>2) * LFO_STEP_TIME) + LFO_STEP_TIME;
           tuningWord = 0x01000000 * fout / clock;
           onLFORate=ADC_CONVERT_TIME;
        }
    }    
}