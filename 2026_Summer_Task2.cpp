#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(void)
{
    // 使用するカードの枚数
    const int CARD = 3;

    // 使用する数字の種類
    const int CARD_NUMBER = 10;

    // 変数
    int i, hit = 0;
    int playerCard[CARD];
    int enemyCard[CARD];
    int plyChoice[CARD];
    int emyChoice[CARD];

    // trueならプレイヤーのターン
    // falseならCPUのターン
    bool trunFlag = true;

    // 勝利判定
    bool judgementFlag = false;

    // 乱数の初期化
    srand((unsigned int)time(NULL));

    // 3つずつランダムな数字
    for (i = 0; i < CARD; i++)
    {
        playerCard[i] = rand() % CARD_NUMBER;
        enemyCard[i] = rand() % CARD_NUMBER;
    }

    cout << "===================   Hit & Blow   ============================" << "\n";
    cout << "3マスの数字あてゲームプレイヤーとCPUが、お互いに隠し持った3つの数字を当てるターン制のゲーム" << "\n";
    cout << "あなたの配られてカードは," << "\n";

    // 3つの数字を表示する
    for (i = 0; i < CARD; i++)
    {
        cout << i + 1 << "番目" << playerCard[i] << "\n";
    }

    cout << "===================   GAME STRAT   ============================" << "\n";

    // 3Hitするまでゲームを繰り返す
    while (true)
    {
        // プレイヤーのターン
        if (trunFlag)
        {
            // 数をリセットする
            hit = 0;

            cout << "PLAYER TRUN 「数字の0から9までの数字を3つ選んでください」\n";

            // プレイヤーが3つの予想数字を入力する
            for (i = 0; i < CARD; i++)
            {
                while (true)
                {
                    cin >> plyChoice[i];

                    // 0～9以外の数字が入力された場合は再入力
                    if (0 > plyChoice[i] || 9 < plyChoice[i])
                    {
                        cout << "入力に誤りがあります。再度入力してください。\n";
                    }
                    else
                    {
                        break;
                    }
                }
            }

            // 入力した数字とCPUの数字を同じ位置で比較
            for (i = 0; i < CARD; i++)
            {
                if (plyChoice[i] == enemyCard[i])
                {
                    cout << "Hit,";
                    hit++;
                }
                else
                {
                    cout << "Blow,";
                }
            }

            cout << "\n";

            // 3つすべてが同じ位置ならプレイヤーの勝利
            if (hit == 3)
            {
                cout << "3Hit!!\n";
                judgementFlag = true;
                break;
            }

            // プレイヤーのターンが終了したのでCPUのターンへ切り替える
            cout << "\n";
            trunFlag = false;
        }
        else
        {
            // CPUのターン開始時にHit数をリセットする
            hit = 0;

            cout << "ENEMY TRUN \n";

            // CPUが0～9の数字を3つランダムに選ぶ
            for (i = 0; i < CARD; i++)
            {
                emyChoice[i] = rand() % CARD_NUMBER;
                cout << i + 1 << "番目" << emyChoice[i] << "\n";
            }

            // CPUの予想とプレイヤーの数字を同じ位置で比較する
            for (i = 0; i < CARD; i++)
            {
                if (emyChoice[i] == playerCard[i])
                {
                    cout << "Hit,";
                    hit++;
                }
                else
                {
                    cout << "Blow,";
                }
            }

            cout << "\n";

            // CPUが3つすべてを正しい位置で当てたらゲーム終了
            if (hit == 3)
            {
                cout << "3Hit!!\n";
                break;
            }

            // CPUのターンが終了したのでプレイヤーのターンへ戻す
            cout << "\n";
            trunFlag = true;
        }
    }

    // プレイヤーが勝ったかCPUが勝ったかを表示する
    if (judgementFlag)
    {
        cout << "PLAYER WINNER\n";
    }
    else
    {
        cout << "ENEMY WINNER\n";
    }

    return 0;
}