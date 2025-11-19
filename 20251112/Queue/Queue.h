#pragma once

const int ARRAY_SIZE = 50;

class Queue{
public:
    Queue();
    void enqueue(char c);
    void print();
    char dequeue();
private:
    int enqueueIndex;
    int dequeueIndex;
    int sizeCount;
    char array[ARRAY_SIZE];
};