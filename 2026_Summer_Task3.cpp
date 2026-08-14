#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    // プレイヤーの手（0:グー、1:チョキ、2:パー）
    int player;

    // CPUの手
    int cpu;

    // プレイヤーとCPUの手から勝敗を判定するための値
    int result;

    // 回数カウント
    int i;

    // プレイヤーの勝利数、敗北数、引き分け数
    int win = 0;
    int lose = 0;
    int draw = 0;

    // 乱数の初期化
    srand((unsigned int)time(nullptr));

    cout << "じゃんけんゲームを開始します。" << endl;

    // 全5回戦
    for (i = 0; i < 5; i++)
    {
        cout << endl;
        cout << "-------- " << i + 1 << "回戦 --------" << endl;

        // 入力チェック
        while (true)
        {
            cout << "0：グー　1：チョキ　2：パー" << endl;
            cout << "プレイヤーの手を入力してください：" << endl;

            cin >> player;

            if (player >= 0 && player <= 2)
            {
                // 範囲チェック
                break;
            }
            cout << "入力に誤りがあります。再入力してください。" << endl;
        }

        // CPUの手
        cpu = rand() % 3;

        // プレイヤーの選択した手を文字で表示する
        switch (player)
        {
        case 0:
            cout << "PLAYER：グー" << endl;
            break;

        case 1:
            cout << "PLAYER：チョキ" << endl;
            break;

        case 2:
            cout << "PLAYER：パー" << endl;
            break;
        }

        // CPUの選択した手を文字で表示する
        switch (cpu)
        {
        case 0:
            cout << "CPU：グー" << endl;
            break;

        case 1:
            cout << "CPU：チョキ" << endl;
            break;

        case 2:
            cout << "CPU：パー" << endl;
            break;
        }

        // プレイヤーとCPUの手の差から勝敗を判定する
        result = player - cpu;

        // Playerの勝利条件
        if (result == -1 || result == 2)
        {
            cout << "PLAYER WIN!" << endl;
            win++;
        }
        // 引き分け
        else if (result == 0)
        {
            cout << "DRAW" << endl;
            draw++;
        }
        // CPUの勝ち
        else
        {
            cout << "CPU WIN!" << endl;
            lose++;
        }
    }

    // 最終結果を表示する
    cout << endl;
    cout << "==============================" << endl;
    cout << "5回勝負終了！" << endl;
    cout << win << "勝 "
        << draw << "分 "
        << lose << "敗" << endl;
    cout << "==============================" << endl;

    return 0;
}