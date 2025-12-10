#pragma once
#include <Queue>
#include <vector>
#include "Constant.h"
#include "Cell.h"

struct SeachState{
    std::queue<Cell> goPosition;
    Cell nowPosition = START;
    std::vector<Cell> wentPosition;
    std::vector<Cell> isAdded;
    bool finished = false;
    bool isGoal = false;
};
void checkGoal(SeachState& seach);
void drawDFS(std::vector<Cell>& wentPos, Cell& nowPos);