#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// ========================================
// 定数
// ========================================

// マスの数（1～9）
const int BOARD_SIZE = 9;

// サイコロの面数
const int DICE_MAX = 6;


// ========================================
// 盤面を表示する関数
// ========================================

void ShowBoard(int board[])
{
    cout << "\n========== JACKPOT ==========\n";

    // 1～9のマス番号を表示
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        cout << i + 1 << " ";
    }

    cout << "\n";

    // 盤面の取得状況を表示
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board[i] == 0)
        {
            // まだ誰も取っていない
            cout << "- ";
        }
        else if (board[i] == 1)
        {
            // プレイヤーが取得
            cout << "P ";
        }
        else
        {
            // CPUが取得
            cout << "C ";
        }
    }

    cout << "\n";
    cout << "P：PLAYER / C：CPU\n";
}


// ========================================
// サイコロを振る関数
// ========================================

void RollDice(int& dice1, int& dice2)
{
    // 1～6のランダムな数字を2個作る
    dice1 = rand() % DICE_MAX + 1;
    dice2 = rand() % DICE_MAX + 1;
}


// ========================================
// 取得可能なマスがあるか確認する関数
// ========================================

bool CanTake(int dice1, int dice2, int board[])
{
    // 取得できる可能性がある3つの数字
    int choices[3];

    choices[0] = dice1;
    choices[1] = dice2;
    choices[2] = dice1 + dice2;

    // 3つの候補を確認する
    for (int i = 0; i < 3; i++)
    {
        int number = choices[i];

        // 1～9の範囲で、まだ取られていない場合
        if (number >= 1 &&
            number <= 9 &&
            board[number - 1] == 0)
        {
            return true;
        }
    }

    // 取得できるマスがない
    return false;
}


// ========================================
// プレイヤーが取得するマスを選ぶ関数
// ========================================

int PlayerChoice(int dice1, int dice2, int board[])
{
    int choices[3];

    choices[0] = dice1;
    choices[1] = dice2;
    choices[2] = dice1 + dice2;

    while (true)
    {
        int choice;

        cout << "取得するマスを入力してください：";
        cin >> choice;

        // 選択可能な3つの数字と比較
        for (int i = 0; i < 3; i++)
        {
            if (choice == choices[i] &&
                choice >= 1 &&
                choice <= 9 &&
                board[choice - 1] == 0)
            {
                return choice;
            }
        }

        // 選択できない場合
        cout << "そのマスは取得できません。\n";
        cout << "もう一度入力してください。\n";
    }
}


// ========================================
// CPUが取得するマスを選ぶ関数
// ========================================

int CPUChoice(int dice1, int dice2, int board[])
{
    int choices[3];

    choices[0] = dice1;
    choices[1] = dice2;
    choices[2] = dice1 + dice2;

    // 取得できるマスを順番に確認する
    for (int i = 0; i < 3; i++)
    {
        int choice = choices[i];

        if (choice >= 1 &&
            choice <= 9 &&
            board[choice - 1] == 0)
        {
            return choice;
        }
    }

    return -1;
}


// ========================================
// すべてのマスが取得されたか確認する関数
// ========================================

bool IsAllTaken(int board[])
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        // まだ取得されていないマスがある
        if (board[i] == 0)
        {
            return false;
        }
    }

    // すべて取得されている
    return true;
}


// ========================================
// メイン処理
// ========================================

int main()
{
    // 乱数を初期化
    srand((unsigned int)time(nullptr));

    // ----------------------------------------
    // 盤面
    //
    // 0：未取得
    // 1：プレイヤー
    // 2：CPU
    // ----------------------------------------

    int board[BOARD_SIZE] = {};

    // true：プレイヤー
    // false：CPU
    bool playerTurn = true;

    cout << "=================================\n";
    cout << "          JACKPOT\n";
    cout << "=================================\n";
    cout << "CPUとプレイヤーで1～9のマスを取り合います。\n";
    cout << "2個のサイコロを振り、出た目または合計から\n";
    cout << "1つを選んでマスを取得してください。\n";


    // ========================================
    // ゲームループ
    // ========================================

    while (true)
    {
        // 現在の盤面を表示
        ShowBoard(board);

        int dice1;
        int dice2;

        // サイコロを2個振る
        RollDice(dice1, dice2);

        // ------------------------------------
        // ターン表示
        // ------------------------------------

        if (playerTurn)
        {
            cout << "\n【PLAYERのターン】\n";
        }
        else
        {
            cout << "\n【CPUのターン】\n";
        }

        cout << "サイコロ1：" << dice1 << "\n";
        cout << "サイコロ2：" << dice2 << "\n";
        cout << "合計：" << dice1 + dice2 << "\n";


        // ------------------------------------
        // 取得できるマスがあるか確認
        // ------------------------------------

        if (!CanTake(dice1, dice2, board))
        {
            cout << "\n取得できるマスがありません。\n";

            // 取得できなかったプレイヤーの負け
            if (playerTurn)
            {
                cout << "PLAYERの負けです！\n";
            }
            else
            {
                cout << "CPUの負けです！\n";
            }

            break;
        }


        // ------------------------------------
        // プレイヤーのターン
        // ------------------------------------

        if (playerTurn)
        {
            cout << "\n取得可能なマス：";
            cout << dice1 << " / ";
            cout << dice2 << " / ";
            cout << dice1 + dice2 << "\n";

            // プレイヤーがマスを選択
            int choice = PlayerChoice(dice1, dice2, board);

            // プレイヤーのマスとして登録
            board[choice - 1] = 1;

            cout << choice << "のマスをPLAYERが取得しました！\n";
        }


        // ------------------------------------
        // CPUのターン
        // ------------------------------------

        else
        {
            cout << "\n取得可能なマス：";
            cout << dice1 << " / ";
            cout << dice2 << " / ";
            cout << dice1 + dice2 << "\n";

            // CPUがマスを選択
            int choice = CPUChoice(dice1, dice2, board);

            // CPUのマスとして登録
            board[choice - 1] = 2;

            cout << choice << "のマスをCPUが取得しました！\n";
        }


        // ------------------------------------
        // すべてのマスが取得されたか確認
        // ------------------------------------

        if (IsAllTaken(board))
        {
            ShowBoard(board);

            cout << "\nすべてのマスが取得されました！\n";

            // 最後に取得したプレイヤーが勝利
            if (playerTurn)
            {
                cout << "PLAYERの勝利です！\n";
            }
            else
            {
                cout << "CPUの勝利です！\n";
            }

            break;
        }


        // ------------------------------------
        // 次のプレイヤーへターン交代
        // ------------------------------------

        playerTurn = !playerTurn;
    }

    return 0;
}