#pragma once

const int ARRAY_SIZE = 50;

class Stack{
public:
    Stack();
    void push(char c);
    void print();
    char pop();
private:
 int index;
 char array[ARRAY_SIZE];
};