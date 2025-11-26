#pragma once
#include "Cell.h"
const int MAP_WIDTH = 8;
const int MAP_HEIGHT = 8;
const int START_POSITION_X = 2;
const int START_POSITION_Y = 3;
const int GOAL_POSITION_X = 6;
const int GOAL_POSITION_Y = 6;
const int AROUND_COUNT = 4;

const bool FIELD[MAP_WIDTH][MAP_HEIGHT] = 
{
    {true, true, false, true, true, true, true, true},
    {true, false, false, true, false, true, false, true},
    {true, false, false, true, false, true, false, true},
    {true, true, true, true, false, true, false, true},
    {true, false, true, false, false, false, true, true},
    {true, false, true, false, false, true, true, false},
    {true, true, true, false, false, false, true, false},
    {true, false, true, true, true, false, true, false},
};

const Cell UP = {0, 1};
const Cell DOWN = {0, -1};
const Cell RIGHT = {1, 0};
const Cell LEFT = {-1, 0};
const Cell START = {START_POSITION_X, START_POSITION_Y};
const Cell GOAL = {GOAL_POSITION_X, GOAL_POSITION_Y};
