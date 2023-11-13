// blackjack2.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "CardCheckr.h"
#include "Card.h"
#include "Status.h"
#include "Player.h"
#include "Dealer.h"
using namespace std;

const int MARK = 4;
const int NUMBER = 13;

Card MakeRandomCard();
void CardShow(Status& other, int Index);//カード情報表示
void GeneralInformationShow(Player& player, Dealer& dealer);//全体情報表示

int main()
{
    std::srand(time(NULL));

    Player player;
    Dealer dealer;
    bool Pburst = false;//プレイヤーのバースト判定
    bool Dburst = false;//ディーラーのバースト判定
    int input = 0;//入力用

    //プレイヤーの処理
    do {
        player.set_outwardlyNum();//表向きの枚数＋１
        GeneralInformationShow(player, dealer);

        if (player.get_score() > 21) {
            cout << "バーストしました" << endl << endl;
            Pburst = true;
            input = 1;
            continue;
        }

        cout << "1:スタンド  1以外の数:ヒット   ＞  " << flush;
        cin >> input;
    } while (input != 1);

    //ディーラーの処理
    if (!Pburst) {
        do {
            dealer.set_outwardlyNum();//表向きの枚数＋１
            GeneralInformationShow(player, dealer);
        } while (dealer.get_score() < 17);
        //ディーラーのバースト判定
        if (dealer.get_score() > 21)Dburst = true;
    }

    //結果表示
    if ((!Pburst && !Dburst && player.get_score() > dealer.get_score()) || Dburst) {
        cout << "プレイヤーの勝ちです" << endl;
    }
    else if (player.get_score() == dealer.get_score()) {
        cout << "引き分けです" << endl;
    }
    else {
        cout << "プレイヤーの負けです" << endl;
    }
}

Card MakeRandomCard()
{
    //カードの使用状況
    static int cardUsageStatus[MARK][NUMBER] = { 0 };//初期化は全カードを未使用状態にする

    int mark = 0;
    int number = 0;

    //使用済みのカードを使えないようにする
    do {
        mark = rand() % MARK + 1;
        number = rand() % NUMBER + 1;
    } while (cardUsageStatus[mark - 1][number - 1] == 1);

    //使用済みにする
    cardUsageStatus[mark - 1][number - 1] = 1;

    Card random((Mark)mark, (CardCheckr)number);

    return random;
}

void CardShow(Status& other, int Index)
{

    switch (other.get_pcard(Index).get_mark()) {
    case spade: printf("スペード   の"); break;
    case heart: printf("ハート     の"); break;
    case diamond: printf("ダイヤ    の: "); break;
    case clover: printf("クローバー の"); break;
    }

    switch (other.get_pcard(Index).get_Number()) {
    case ace: printf("A"); break;
    case two: printf("2"); break;
    case three: printf("3"); break;
    case four: printf("4"); break;
    case five: printf("5"); break;
    case six: printf("6"); break;
    case seven: printf("7"); break;
    case eight: printf("8"); break;
    case nine: printf("9"); break;
    case ten: printf("10"); break;
    case jack: printf("J"); break;
    case queen: printf("Q"); break;
    case king: printf("K"); break;
    }
    cout << endl;
}

void GeneralInformationShow(Player& player, Dealer& dealer)
{
    system("cls");

    //得点をリセット
    player.set_score(reset);
    dealer.set_score(reset);

    cout << "自分の手札" << endl;
    for (int i = 0; i < player.get_outwardlyNum(); ++i) {
        CardShow(player, i);
    }
    player.PlayerScoreCalculation();
    cout << "点数 : " << player.get_score() << endl << endl;


    cout << "ディーラーの手札" << endl;
    for (int i = 0; i < dealer.get_outwardlyNum(); ++i) {
        CardShow(dealer, i);
    }
    dealer.DealerScoreCalculation();
    cout << "点数 : " << dealer.get_score() << endl << endl;
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
