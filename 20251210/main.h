#pragma once
#include <Queue>
#include <vector>
#include "Constant.h"
#include "Cell.h"

struct SeachState{
    std::queue<Cell> goPosition;
    Cell nowPosition = START;
    std::vector<Cell> wentPosition;
    bool finished = false;
    bool isGoal = false;
};
bool checkGoal(SeachState& seach);