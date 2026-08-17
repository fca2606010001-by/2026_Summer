#include <iostream>
using namespace std;

#include "20260817_Prac1_header.h"

//ピッチャーの種類
void PitingType(int piting)
{
    //スイッチ関数
    switch (piting)
    {
	case 0:
		cout << "ストレートを投げました" << endl;
		break;
	case 1:
		cout << "カーブを投げました" << endl;
		break;
	case 2:
		cout << "スライダーを投げました" << endl;
		break;
	case 3:
		cout << "シンカーを投げました" << endl;
		break;

    }
}

//投球結果
void Result(int out)
{
	//結果の表示
    if (out >= 3)
    {
        cout << "PLAYER WINNER!!" << endl;
    }
    else
    {
        cout << "CPU WINNER!!" << endl;
    }
}