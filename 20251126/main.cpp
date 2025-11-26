#include <iostream>
#include <stack>
#include <thread>
#include <chrono>
#include <atomic>
#include <vector>
#include <algorithm>
#include "Constant.h"
#include "main.h"

// 0.5秒ごとに処理
void periodicTask(SeachState& seach){
    using namespace std::chrono_literals; // 500msを使う
    auto const NEXT_RUN_TIME = 500ms;
    while(!seach.finished){
        std::cout << "別スレッド0.5秒ごとに実行中" << "\n";
        stepSeach(seach);


        // 次の実行までの時間を計算し、スリープする
        auto nextRunTime = std::chrono::steady_clock::now() + NEXT_RUN_TIME;
        std::this_thread::sleep_until(nextRunTime);
    }
    std::cout << "作業が終了しました。" << "\n";
}

int main(){
    SeachState state{};
    std::cout << "メインスレッド開始。別のスレッドを起動します" << "\n";

    // 別スレッド(threadの引数は第一引数に呼び出す関数名、それ以降は渡す引数)
    std::thread task_thread(periodicTask, std::ref(state));
    std::cout << "メインスレッド : ほかの作業を実行中" << "\n";

    // 別スレッドが処理を終了するまで待つ
    if(task_thread.joinable()){
        task_thread.join();
    }


    if(state.isGoal) {
        std::cout << "ゴールまで行けます" << "\n";
    }
    else {
        std::cout << "ゴールまでたどり着けませんでした" << "\n";
    }
    std::cout << std::endl;
    return 0;
}

void stepSeach(SeachState& seach){ 
  
    auto& goPosition  = seach.goPosition;
    auto& wentPosition = seach.wentPosition;
    auto& nowPosition = seach.nowPosition;

    // すでに終わってるなら何もしない
    if (seach.finished) return;

    // 今いるマスを登録
    wentPosition.push_back(nowPosition);

    // 行ける場所をスタックに入れる

    // ラムダ式を使ってみる
    auto contains = [](const std::vector<Cell>& v, const Cell& c) {
        return std::find(v.begin(), v.end(), c) != v.end();
    };

    auto inRange = [](const Cell& pos){
        return (pos.x >= 0) && (pos.x < MAP_WIDTH) &&
        (pos.y >= 0) && (pos.y < MAP_HEIGHT);
    };

    Cell rightPos = nowPosition + RIGHT;
    Cell upPos    = nowPosition + UP;
    Cell leftPos  = nowPosition + LEFT;
    Cell downPos  = nowPosition + DOWN;
    
    // 隣にゴールがあるかを見る
    Cell neighbors[NEIGHBORS_COUNT] = {rightPos, upPos, leftPos, downPos};
    for(auto& n : neighbors){
        if(!inRange(n)) continue;
        if(!FIELD[n.x][n.y]) continue;
        if(contains(wentPosition, n)) continue;

        if(n == GOAL){
            nowPosition = n;
            wentPosition.push_back(nowPosition);
            seach.isGoal = true;
            seach.finished = true;
            drawDFS(wentPosition, nowPosition);
            return;
        }
    }

    // 隣にゴールがないならスタックを積む
    auto pushIfCanGo = [&](const Cell& pos) {
        if (!inRange(pos)) return;

        if (!FIELD[pos.x][pos.y]) return;
        if (contains(wentPosition, pos)) return;

        goPosition.push(pos);
    };

    pushIfCanGo(rightPos);
    pushIfCanGo(upPos);
    pushIfCanGo(leftPos);
    pushIfCanGo(downPos);

    // 次に行ける場所を見る(ないならゴールなし)

    if (goPosition.empty()) {
        // もうどこにも行けないならゴールなし
        seach.isGoal = false;
        seach.finished = true;
        return;
    }

    // 次のステップの nowPosition をここで決める
    nowPosition = goPosition.top();
    goPosition.pop();

     // 描画
    drawDFS(wentPosition, nowPosition);
    }

void drawDFS(std::vector<Cell>& wnetPos, Cell& nowPos){
    for(int x = 0; x < MAP_WIDTH; ++x){
        for(int y = 0; y < MAP_HEIGHT; ++y){
            bool drawPos = FIELD[x][y];
            
            if(drawPos){
                if(Cell(x, y) == nowPos){
                    std::cout << "あ";
                }
                else{
                    bool isVisit = false;
                    for(auto& c : wnetPos){
                        if(Cell(x, y) == c) {
                            isVisit = true;
                            break;
                        }
                    }

                    if(isVisit){
                        std::cout << "🔼";
                    }
                    else{
                        std::cout << "🔲";
                    }
                }
            }
            else{
                std::cout << "🔳";
            }
        }
        std::cout << "\n";
    }
    std::cout << "\n\n\n";
}
