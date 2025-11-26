#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include "Constant.h"
#include "Cell.h"
#include "main.h"

int main(){
    SeachState seach;
    if(checkGoal(seach)) {
        std::cout << "ゴールまで行けます" << "\n";
    }
    else {
        std::cout << "ゴールまでたどり着けませんでした" << "\n";
    }
    std::cout << std::endl;
    return 0;
}

bool checkGoal(SeachState& seach){ 

    // 今の位置がゴール位置と一緒でないなら探索する
    while (true)
    {
        auto& goPosition  = seach.goPosition;
        auto& wentPosition = seach.wentPosition;
        auto& nowPosition = seach.nowPosition;

        // すでに終わってるなら何もしない
        if (nowPosition == GOAL) return true;

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
                return true;
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
            return false;
        }

        // 次のステップの nowPosition をここで決める
        nowPosition = goPosition.top();
        goPosition.pop();
    }

    return false;
    
}