#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    // ランダムな数字
    int answer = -1;

    // プレイヤーが入力した数字
    int question;

    // 正解するまでに入力した回数
    int count = 0;

    // 乱数の初期化
    srand((unsigned int)time(nullptr));

    // 0～100の範囲から正解の数字をランダムに1つ決める
    question = rand() % 101;

    cout << "数字当てゲーム" << endl;
    cout << "0～100までの数字を当ててください。" << endl;

    // プレイヤーが正解するまで繰り返す
    while (question != answer)
    {
        // 予想した回数を増やす
        count++;

        // 範囲チェック
        while (true)
        {
            cout << "0～100の数字を入力してください：" << endl;
            cin >> answer;

            // 0～100以外の数字が入力された場合は再入力
            if (answer < 0 || answer > 100)
            {
                cout << "入力に誤りがあります。再入力してください。" << endl;
            }
            else
            {
                break;
            }
        }

        // 正解より入力した数字が小さい場合
        if (question > answer)
        {
            cout << "もっと大きい数字です。" << endl;
        }
        // 正解より入力した数字が大きい場合
        else if (question < answer)
        {
            cout << "もっと小さい数字です。" << endl;
        }
    }

    // 正解と、正解までの回数を表示する
    cout << endl;
    cout << "おめでとうございます！正解です！" << endl;
    cout << "正解：" << answer << endl;
    cout << count << "回目で当てることができました。" << endl;

    return 0;
}