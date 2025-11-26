#pragma once
#include <vector>
#include "Cell.h"

struct SeachState{
    std::stack<Cell> goPosition;
    Cell nowPosition = START;
    std::vector<Cell> wentPosition;
    bool finished = false;
    bool isGoal = false;
};
void stepSeach(SeachState& seach);
void drawDFS(std::vector<Cell>& wnetPos, Cell& nowPos);