#include <iostream>
#include <Queue>
#include <vector>
#include <thread>
#include <chrono>
#include <atomic>
#include <algorithm>
#include "Constant.h"
#include "Cell.h"
#include "main.h"

// 0.5秒ごとに処理
void periodicTask(SeachState& seach){
    using namespace std::chrono_literals; // 500msを使う
    auto const NEXT_RUN_TIME = 500ms;
    while(!seach.finished){
        std::cout << "別スレッド0.5秒ごとに実行中" << "\n";
        checkGoal(seach);


        // 次の実行までの時間を計算し、スリープする
        auto nextRunTime = std::chrono::steady_clock::now() + NEXT_RUN_TIME;
        std::this_thread::sleep_until(nextRunTime);
    }
    std::cout << "作業が終了しました。" << "\n";
}

// Cellの中身を表示するための関数
// ポイント：引数を「参照(&)」ではなく「値渡し」にすることで、
// 自動的にコピーが作られ、元のキュー(goPosition)は壊れません。
void printQueue(std::queue<Cell> tempQ) {
    std::cout << "--- Queue Contents (残り: " << tempQ.size() << ") ---\n";
    
    // コピーしたキューが空になるまで回す
    while (!tempQ.empty()) {
        Cell c = tempQ.front(); // 先頭を見る
        std::cout << "(" << c.x << "," << c.y << ") ";
        tempQ.pop();            // 先頭を捨てる（コピーだから大丈夫）
    }
    std::cout << "\n--------------------------------------\n";
}

int main(){
    SeachState state; // 探索用構造体のインスタンスを作る

    std::cout << "メインスレッド開始。別のスレッドを起動します" << "\n";

    // 別スレッド(threadの引数は第一引数に呼び出す関数名、それ以降は渡す引数)
    std::thread task_thread(periodicTask, std::ref(state));
    std::cout << "メインスレッド : ほかの作業を実行中" << "\n";

    // 別スレッドが処理を終了するまで待つ
    if(task_thread.joinable()){
        task_thread.join();
    }

    if(state.isGoal){
        std::cout << "ゴールまで行けます!\n";
    }
    else {
        std::cout << "ゴールまで行けません!\n";
    }


    return 0;
}

void checkGoal(SeachState& seach){
    // それぞれの状態を変数化する
    auto& isAdded = seach.isAdded;
    auto& goPosition = seach.goPosition;
    auto& wentPosition = seach.wentPosition;
    auto& nowPosition = seach.nowPosition;
    // 今いる位置がゴールならtrueを返す
    if(nowPosition == GOAL) {
        seach.isGoal = true;
        seach.finished = true;
        return;
    }


    // 今いる位置を行った場所に登録
    wentPosition.push_back(nowPosition);

    // 第一引数の範囲に第二引数のものがないのかを調べる関数
    auto contains = [](const std::vector<Cell>& v, const Cell& c){
        return std::find(v.begin(), v.end(), c) != v.end();
    };

    // 範囲内かどうかを調べる関数
    auto isRange = [](const Cell& pos){
        return (0 <= pos.x) && (MAP_WIDTH > pos.x) && (0 <= pos.y) && (MAP_HEIGHT > pos.y);
    };


    // 左右上下を定義する
    Cell right = nowPosition + RIGHT; // 右
    Cell left = nowPosition + LEFT; // 左
    Cell up = nowPosition + UP; // 上
    Cell down = nowPosition + DOWN; // 下

    // いける範囲にキューを積む
    auto pushIfCanGo = [&](const Cell pos){
        if(!isRange(pos)) return; // マップ範囲外ならreturn
        if(!FIELD[pos.x][pos.y]) return; // 位置が進めない場所ならreturn
        if(contains(wentPosition, pos)) return; // 過去に行ったことがある位置ならreturn

        for(auto& c : isAdded){
            if(pos == c) return;
        }

        goPosition.push(pos); // ここまで通ったらキューに追加する
        isAdded.push_back(pos);
    };

    // 各方向に対してPushIfCanGoを実行していく(反時計回り)
    pushIfCanGo(left); // 左側に行けるなら行く
    pushIfCanGo(down); // 下側に行けるなら行く
    pushIfCanGo(right); // 右側に行けるなら行く
    pushIfCanGo(up); // 上側に行けるなら行く

    // いける場所が空 = ゴールなしと判定する
    if(goPosition.empty()){
        seach.isGoal = false; // ゴールなしとする
        seach.finished = true; // 作業終了
        return;
    }

    // 現在位置の更新
    nowPosition = goPosition.front(); // FIFOなので先頭要素を取る
    goPosition.pop(); // 先頭を削除する

    drawDFS(wentPosition, nowPosition); // 描画
    printQueue(goPosition);
}


// フィールドと今自分がいる位置といった場所を表示する関数
void drawDFS(std::vector<Cell>& wentPos, Cell& nowPos){
    // 二重for文を使って全体を回す
    for(int x = 0; x < MAP_WIDTH; ++x){
        for(int y = 0; y < MAP_HEIGHT; ++y){
            bool drawPos = FIELD[x][y]; // 表示する場所の変数
            // まず動くことが可能な位置とそうでない位置の条件で表示するタイルを分ける
            if(drawPos){
                // 自分がいる位置は「あ」と表示する
                if(nowPos == Cell(x, y)){
                    std::cout << "あ";
                }
                else{
                    bool isVisit = false; // いったことがあるかどうかに使うフラグ
                    for(auto& w : wentPos){
                        // いったことがある場所ならisVisitをtrueにして抜ける
                        if(w == Cell(x, y)){
                            isVisit = true;
                            break;
                        }
                    }
                    
                    // isVisitによって表示するものを分ける
                    if(isVisit){
                        // いったことがある場所
                        std::cout <<  "🔼";
                    }
                    else{
                        // いける場所
                        std::cout << "🔲";
                    }
                }
            }
            else{
                std::cout << "🔳"; // いけない場所
            }
        }
        std::cout << "\n";
    }
    std::cout << "\n\n\n";
}
