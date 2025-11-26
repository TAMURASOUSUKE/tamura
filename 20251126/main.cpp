#include <iostream>
#include "Constant.h"
#include <stack>
#include <vector>

bool checkGoal();

int main(){
    if(checkGoal()) {
        std::cout << "ゴールまで行けます" << "\n";
    }
    else {
        std::cout << "ゴールまでたどり着けませんでした" << "\n";
    }
    std::cout << std::endl;
    return 0;
}

bool checkGoal(){ 
    std::stack<Cell> goPosition{};
    Cell nowPosition = START;
    std::vector<Cell> wentPosition{};

    // 今の位置がゴール位置と一緒でないなら探索する
    while (true)
    {
        if(nowPosition == GOAL) return true;
        

        // 自分の位置の更新
        wentPosition.push_back(nowPosition); // いた位置を追加して移動する
        if(!goPosition.empty()){
            nowPosition = goPosition.top(); // stackの最後に入っている行ける位置に移動
            goPosition.pop(); // stackの最後の要素を削除
        }

        // ゴールチェック用の変数
        bool isCorectPosition = FIELD[nowPosition.x][nowPosition.y]; // グレーの場所にいないかのチェック
        bool upCheck = nowPosition + UP == Cell(GOAL_POSITION_X, GOAL_POSITION_Y);
        bool leftCheck = nowPosition + LEFT == Cell(GOAL_POSITION_X, GOAL_POSITION_Y);
        bool downCheck = nowPosition + DOWN == Cell(GOAL_POSITION_X, GOAL_POSITION_Y);
        bool rightCheck = nowPosition + RIGHT == Cell(GOAL_POSITION_X, GOAL_POSITION_Y);
        // いける位置を計算しゴールチェックする
        // ゴールチェック(ゴールになるならそこに移動する)
        if(upCheck && isCorectPosition) nowPosition += UP;
        else if(leftCheck && isCorectPosition) nowPosition += LEFT;
        else if(downCheck && isCorectPosition) nowPosition += DOWN;
        else if(rightCheck && isCorectPosition) nowPosition += RIGHT;



        // いける位置を追加する

        // 右
        int rx = nowPosition.x + RIGHT.x;
        int ry = nowPosition.y + RIGHT.y;
        bool canCheckRight = 0 <= rx && rx < MAP_WIDTH && 0 <= ry && ry < MAP_HEIGHT;
        bool isRight = false;
        if(canCheckRight) isRight = FIELD[rx][ry];
        bool wentRight = false;

        // 左 
        int lx = nowPosition.x + LEFT.x;
        int ly = nowPosition.y + LEFT.y;
        bool canCheckLeft = 0 <= lx && lx < MAP_WIDTH && 0 <= ly && ly < MAP_HEIGHT;
        bool isLeft = false;
        if(canCheckLeft) isLeft = FIELD[lx][ly];
        bool wentLeft = false;

        // 上
        int ux = nowPosition.x + UP.x;
        int uy = nowPosition.y + UP.y;
        bool canCheckUp = 0 <= ux && ux < MAP_WIDTH && 0 <= uy && uy < MAP_HEIGHT;
        bool isUp = false;
        if(canCheckUp) isUp = FIELD[ux][uy];
        bool wentUp = false;

        // 下
        int dx = nowPosition.x + DOWN.x;
        int dy = nowPosition.y + DOWN.y;
        bool canCheckDown = 0 <= dx && dx < MAP_WIDTH && 0 <= dy && dy < MAP_HEIGHT;
        bool isDown = false;
        if(canCheckDown) isDown = FIELD[dx][dy];
        bool wentDown = false;
        // 行こうとしている位置が過去に行ったことあるかどうかを判定する
        for (int i = 0; i < wentPosition.size(); ++i) {
            if ((nowPosition + RIGHT) == wentPosition[i]) wentRight = true;
            if ((nowPosition + LEFT)  == wentPosition[i]) wentLeft  = true;
            if ((nowPosition + UP)    == wentPosition[i]) wentUp    = true;
            if ((nowPosition + DOWN)  == wentPosition[i]) wentDown  = true;
        }

        if(isUp && !wentUp) goPosition.push(nowPosition + UP);
        if(isLeft && !wentLeft) goPosition.push(nowPosition + LEFT);
        if(isDown && !wentDown) goPosition.push(nowPosition + DOWN);
        if(isRight && !wentRight) goPosition.push(nowPosition+ RIGHT);

        if(goPosition.empty()) break; // 空になったら処理を抜ける
    }

    return false;
    
}


