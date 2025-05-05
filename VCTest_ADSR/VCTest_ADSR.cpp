// VCTest_ADSR.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//
#define _USE_MATH_DEFINES // for C++
#include <cmath>
#include <iostream>

/*
void ADSR(double e[], int A, int D, double S, int R, int gate, int duration)
{
    int n;

    if (A != 0)
    {
        for (n = 0; n < A; n++)
        {
            e[n] = 1.0 - exp(-5.0 * n / A);
        }
    }

    if (D != 0)
    {
        for (n = A; n < gate; n++)
        {
            e[n] = S + (1 - S) * exp(-5.0 * (n - A) / D);
        }
    }
    else
    {
        for (n = A; n < gate; n++)
        {
            e[n] = S;
        }
    }

    if (R != 0)
    {
        for (n = gate; n < duration; n++)
        {
            e[n] = e[gate - 1] * exp(-5.0 * (n - gate + 1) / R);
        }
    }
}
*/

int main()
{
    uint16_t fs = 44100; /* 標本化周波数 */
    uint16_t bits = 16; /* 量子化精度 */

    double a, f0;
    a = 0.1; /* 振幅 */
    f0 = 440; /* 周波数 */

    double T, nowT;
    T = fs / f0; /*1周期分のインデックス値*/
    nowT = 0; /*現在の周期インデックス値*/

    /*出力するサンプル数 (標本化周波数*秒数)*/
    uint32_t length = fs * 1;
    uint32_t n = 0;

    double Atm = fs * 0.005;    //アタック 2ms～1.5s
    double Dtm = fs * 0.070;    //ディケイ 2ms～5s
    double Slv = 0.5;           //サスティン レベル(0～+1)
    double Stm = fs * 0.100;    //サスティン タイム 0ms～
    double Rtm = fs * 0.020;    //リリース 2ms～5s
    double Rpoint = 0;
    //ADSR(vca, A, D, S, R, gate, duration);

     //アタック 2ms～1.5s
    for (n = 0; n < Atm; n++) {
        Rpoint = 1.0 - exp(-5.0 * n / Atm);
        std::cout << Rpoint << "\n";
    }

    //ディケイ 2ms～5s
    for (; n < Dtm; n++)
    {
        Rpoint = Slv + (1 - Slv) * exp(-5.0 * (n - Atm) / Dtm);
        std::cout << Rpoint << "\n";
    }

    //サスティン 200ms
    for (n = 0; n < Stm; n++)
    {
        Rpoint = Slv;
        std::cout << Rpoint << "\n";
    }

    //リリース 2ms～5s
    for (n=0; n < Rtm; n++)
    {
        Rpoint = Rpoint * exp(-5.0 * n / Rtm);
        std::cout << Rpoint << "\n";
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
