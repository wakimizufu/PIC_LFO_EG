// VCTest_wave.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#define _USE_MATH_DEFINES // for C++
#include <cmath>
#include <iostream>


int main()
{
    //std::cout << "Hello World!\n";

    uint16_t fs = 44100; /* 標本化周波数 */
    uint16_t bits = 16; /* 量子化精度 */

    double a, f0;
    a = 0.1; /* 振幅 */
    f0 = 440; /* 周波数 */

    double T,nowT;
    T = fs / f0; /*1周期分のインデックス値*/
    nowT = 0; /*現在の周期インデックス値*/

    /*出力するサンプル数 (標本化周波数*秒数)*/
    uint32_t length = fs * 1;
    uint32_t n;



    /* サイン波 */
    /*
    for ( n = 0; n < length; n++){

        std::cout << a * sin(2.0 * M_PI * f0 * nowT / fs) << "\n";

        nowT = nowT + 1;
        if (nowT >= T) nowT = nowT - T;
    }
    */
   


    /* 矩形波 */
    /*
    for (n = 0; n < length; n++) {
        if (nowT < T / 2.0)
        {
            std::cout << 1.0 << "\n";
        }
        else
        {
            std::cout << -1.0 << "\n";
        }

        nowT++;
        if (nowT >= T) nowT = nowT - T;
    }
    */



    /* 三角波 */
    /*
    for (n = 0; n < length; n++) {
        if (nowT < T / 2.0)
        {
            std::cout << -1.0 + 4.0 * nowT / T << "\n";
        }
        else
        {
            std::cout << 3.0 - 4.0 * nowT / T << "\n";
        }

        nowT++;
        if (nowT >= T) nowT = nowT - T;
    }
    */


    /* ノコギリ波 */
    /*
    for (n = 0; n < length; n++)
    {
        std::cout << 1.0 - 2.0 * nowT / T << "\n";

        nowT++;
        if (nowT >= T) nowT = nowT - T;
    }
    */


    /*ノコギリ波～三角波*/
    double dt = 0.40;
    double dl_P = 2 / ( (     dt * fs) / fs);
    double dl_N = 2 / ( ( (1-dt) * fs) / fs);
    double nowT_P = 0;

    for (n = 0; n < length; n++) {
        if (nowT < (T* dt) )
        {
            std::cout << -1.0 + (dl_P * nowT / T) << "\n";
            nowT_P = nowT;
        }
        else
        {
            std::cout << -1 * ( - 1.0 + (dl_N * (nowT - nowT_P) / T)) << "\n";
        }

        nowT++;
        if (nowT >= T) nowT = nowT - T;
    }



}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
