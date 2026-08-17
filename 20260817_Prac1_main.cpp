#include <iostream>
#include <cstdlib>
#include <ctime>
#include "20260817_Prac1_header.h"

using namespace std;

//グローバル関数
const int PITING_MIN = 0;
const int PITING_MAX = 3;
const int PROBABILITY = 4;
const int STRIKE_COUNT = 3;
const int BALL_COUNT = 4;
const int OUT_COUNT = 3;
const int HIT_COUNT = 4;

int main(void)
{
    //メイン関数
    int ply, emy;
    int prod;

    //ピッチャーの種類
    int Strike = 0;
    int Ball = 0;
    int Out = 0;
    int Hit = 0;

    //乱数の初期化
    srand((unsigned int)time(NULL));

    //ゲーム開始
    cout << "野球盤ゲームスタートです" << endl;
    cout << "プレイヤーはピッチャーとなり、この回を守り切ってください" << endl;

    //ループ
    while (Out < OUT_COUNT && Hit < HIT_COUNT)
    {
        //投球の説明
        cout << "投げる球を選んでください" << endl;
        cout << "0:ストレート "
            << "1:カーブ "
            << "2:スライダー "
            << "3:シンカー"
            << endl;

        //ループ
        while (true)
        {
            cin >> ply;

            //範囲チェック
            if (PITING_MIN > ply || PITING_MAX < ply)
            {
                cout << "入力に誤りがあります。"
                    << "再度入力してください。"
                    << endl;
            }
            else
            {
                break;
            }
        }

        //ピッチャーの種類
        PitingType(ply);

        //CPUのランダムの初期化
        emy = rand() % PROBABILITY;

        //ランダムの初期化
        prod = rand() % PROBABILITY;

        //プレイヤーとCPUの結果
        if (ply != emy)
        {
            //ボールとストライク
            if (prod == 0)
            {
                cout << "ボール！" << endl;
                Ball++;
            }
            else
            {
                cout << "ストライク！！" << endl;
                Strike++;
            }
        }

        else
        {
            Strike = 0;
            Ball = 0;

            //ヒットとアウト
            if (prod == 1)
            {
                cout << "OUT!!!" << endl;
                Out++;
            }
            else
            {
                cout << "HIT!!" << endl;
                Hit++;
            }
        }

        
        if (Strike >= STRIKE_COUNT || Ball >= BALL_COUNT)
        {
            //ヒットとアウトのカウント
            if (Strike >= STRIKE_COUNT)
            {
                Out++;
            }
            else
            {
                Hit++;
            }

            Strike = 0;
            Ball = 0;
        }

        //試合途中の結果
        cout << "B:" << Ball << endl;
        cout << "S:" << Strike << endl;
        cout << "O:" << Out << endl;
        cout << "Runner:" << Hit << endl;

    } 

    //最終結果
    Result(Out);

    return 0;
}