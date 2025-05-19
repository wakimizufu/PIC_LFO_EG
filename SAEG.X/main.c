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



//LFO サイン波テーブル
# define SINE_CURVE_LENGTH 256
const unsigned int sineTbl[SINE_CURVE_LENGTH] = {
512,524,536,548,560,576,588,600,612,624,636,648,660,672,684,696,708,
716,728,740,752,764,772,784,796,804,816,824,836,844,852,864,872,880,
888,896,904,912,920,928,936,940,948,952,960,964,972,976,980,984,992,
996,1000,1000,1004,1008,1012,1012,1016,1016,1016,1020,1020,1020,1020,1020,1020,1020,
1016,1016,1016,1012,1012,1008,1004,1000,1000,996,992,984,980,976,972,964,960,
952,948,940,936,928,920,912,904,896,888,880,872,864,852,844,836,824,
816,804,796,784,772,764,752,740,728,716,708,696,684,672,660,648,636,
624,612,600,588,576,560,548,536,524,512,500,488,476,464,448,436,424,
412,400,388,376,364,352,340,328,316,308,296,284,272,260,252,240,228,
220,208,200,188,180,172,160,152,144,136,128,120,112,104,96,88,84,
76,72,64,60,52,48,44,40,32,28,24,24,20,16,12,12,8,
8,8,4,4,4,4,4,4,4,8,8,8,12,12,16,20,24,
24,28,32,40,44,48,52,60,64,72,76,84,88,96,104,112,120,
128,136,144,152,160,172,180,188,200,208,220,228,240,252,260,272,284,
296,308,316,328,340,352,364,376,388,400,412,424,436,448,464,476,488,500};


//ADSR カーブテーブル
# define EXP_CURVE_LENGTH 256
/*
const unsigned int curveTbl[EXP_CURVE_LENGTH] = {
0,13,27,40,53,66,79,91,103,115,127,138,149,161,171,182,192,
202,212,222,231,241,250,259,268,277,285,294,302,310,317,325,333,340,
347,354,361,368,375,382,389,395,401,407,413,419,424,430,436,441,447,
452,457,462,467,472,476,481,485,490,494,499,503,507,511,515,519,523,
527,530,534,537,541,544,548,550,554,557,560,563,566,569,572,575,577,
580,583,585,588,590,592,595,597,599,602,604,606,609,611,613,615,616,
618,620,622,624,625,627,629,631,632,634,636,637,639,640,641,643,644,
646,647,648,650,651,653,653,655,656,657,658,660,660,662,662,664,665,
665,667,667,668,669,670,671,672,673,674,674,675,676,676,677,679,679,
680,681,681,681,682,683,683,684,685,686,686,686,687,688,688,689,689,
690,690,690,691,692,692,693,693,693,694,695,695,695,695,696,696,697,
697,697,697,698,698,699,699,700,700,700,700,700,701,701,702,702,702,
702,702,702,703,703,704,704,704,704,704,704,704,705,705,705,706,706,
706,706,707,707,707,707,707,707,707,707,707,708,708,708,708,708,709,
709,709,709,709,709,709,709,709,709,709,710,710,710,710,710,710,710,711};
*/

const unsigned int curveTbl[EXP_CURVE_LENGTH] = {
0,19,39,58,77,95,113,131,148,165,182,198,214,230,245,260,275,
289,304,318,331,345,358,371,383,396,408,420,432,443,454,465,476,487,
497,507,517,527,537,546,556,565,574,582,591,599,607,615,623,631,639,
646,653,661,668,675,681,688,694,701,707,713,719,725,731,737,742,748,
753,758,763,768,773,778,783,787,792,796,801,805,809,814,818,822,825,
829,833,837,840,844,847,851,854,857,861,864,867,870,873,876,879,881,
884,887,889,892,894,897,899,902,904,906,909,911,913,915,917,919,921,
923,925,927,929,931,933,934,936,938,939,941,943,944,946,947,949,950,
951,953,954,955,957,958,959,961,962,963,964,965,966,967,968,970,971,
972,973,974,974,975,976,977,978,979,980,981,981,982,983,984,985,985,
986,987,987,988,989,989,990,991,991,992,993,993,994,994,995,995,996,
996,997,997,998,998,999,999,1000,1000,1001,1001,1001,1002,1002,1003,1003,1003,
1004,1004,1004,1005,1005,1006,1006,1006,1006,1007,1007,1007,1008,1008,1008,1009,1009,
1009,1009,1010,1010,1010,1010,1011,1011,1011,1011,1011,1012,1012,1012,1012,1012,1013,
1013,1013,1013,1013,1014,1014,1014,1014,1014,1014,1015,1015,1015,1015,1015,1015,1015,1016};


//エンベロープ ステータス
enum ENV_ST {
    EMP,    //未出力
    ATK,    //アタック
    DCY,    //ディケイ
    SUS,    //サスティン
    REL     //リリース
};


//ADC変換タイミング(単位:2msec)
#define ADC_CONVERT_TIME 100 

//ADC 8bitに対するLFOステップ周波数(単位:Hz))
#define LFO_STEP_TIME 0.117 



//エンベロープ関連
_Bool envGate = false;
enum ENV_ST env1_ST = EMP;  //現在のエンベロープ ステータス
uint16_t envCount = 0;  //エンベロープカウンタ
uint16_t envDAC   = 0;  //エンベロープ用DAC
uint16_t Atm = 200;     //アタック 2ms:40?1.5s:3000
uint16_t Dtm = 2000;    //ディケイ 2ms:40?5s:10000
uint16_t Slv = 500;     //サスティン レベル(0?1023)
uint16_t Rtm = 1000;    //リリース 2ms:40?5s:10000
uint16_t Rpoint = 0;


// 関数プロトタイプ
void MyTMR1_ISR(void);
void onEdgeGate_ISR(void);
uint16_t getExpIndex(uint16_t value , uint16_t max);
void genEnvelope(void);

// 2000Hz=0.5ms タイマー割込み
void MyTMR1_ISR(void){
    onTMR1 = true;
}

// GATE 入力割込み
void onEdgeGate_ISR(void){
    
    TP_LAT = Gate_GetValue();
    envGate = Gate_GetValue();
    
    if ( envGate ){
        env1_ST = ATK;
        envCount = 0;
    } else if (!envGate) {
        env1_ST = REL;
        envCount = 0;
    }
}

//カーブテーブル値取得関数
uint16_t getExpIndex(uint16_t value , uint16_t max) {
    uint16_t temp = (value / max) * (EXP_CURVE_LENGTH - 1);
    if (temp > (EXP_CURVE_LENGTH - 1) )temp = (EXP_CURVE_LENGTH - 1);
    return temp;
}



void genEnvelope (){

	double dTemp;
	
	switch ( env1_ST ) {
		case EMP:    //未出力
			envDAC	=	0;
			break;

		case ATK:    //アタック
			if ( envCount < Atm ) {
				Rpoint = curveTbl[getExpIndex(envCount, Atm)];
			} else if ( envCount >= Atm ) {
				env1_ST = DCY;
				envCount = 0;
			}
			break;

		case DCY:    //ディケイ
			if ( envCount < Dtm ) {
                dTemp = (double)1023 - curveTbl[getExpIndex(envCount, Dtm)];
                dTemp = Slv + ((1023 - Slv) * (dTemp/1023));
                Rpoint = (uint16_t)dTemp;
			} else if ( envCount >= Dtm ) {
				env1_ST = SUS;
				envCount = 0;
			}
			break;

		case SUS:    //サスティン
			envDAC	=	Slv;
			break;

		case REL:    //リリース
			if ( envCount < Rtm ) {
                dTemp = (double)1023 - curveTbl[getExpIndex(envCount, Rtm)];
                dTemp = ( Rpoint * (dTemp / 1023));
			}  else if ( envCount >= Rtm ) {
                env1_ST = EMP;
                envDAC	=	0;
			}

			break;

		default:
			break;
	}

	envCount++;

	//Envelope⇒PWM1 設定値を変更
	PWM_DAC_LoadDutyValue(envDAC);
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

    Gate_SetInterruptHandler(onEdgeGate_ISR);
    
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
        // 2000Hz=0.5ms タイマー割込み
        if (onTMR1){
            
            //サイン波テーブルから取得
            count = accmulator >> 16;
            dacval = sineTbl[count];
            
            //方形波
            /*
            if (dacval >= 358) {
                dacval=714;
            } else {
                dacval=0;
            }
             */
            
            //LFO⇒PWM2 設定値を変更
            PWM_LFO_LoadDutyValue(dacval);
            //PWM_LFO_LoadDutyValue(ADC_ConversionResultGet());
            
            //加算累積器へ加算
            accmulator += tuningWord;
   
            onLFORate--;            
            onTMR1 = false;
        }
        
        //LFO RATE ADC値をonLFORateへ反映
        if (0 == onLFORate){
           ADC_ChannelSelect(LFORATE); //ADC_CHANNEL_ANA2
           ADC_ConversionStart();
           while(!ADC_IsConversionDone());
            
           fout = ( (ADC_ConversionResultGet()>>2) * LFO_STEP_TIME) + LFO_STEP_TIME;
           tuningWord = 0x01000000 * fout / clock;
           onLFORate=ADC_CONVERT_TIME;
        }
    }    
}