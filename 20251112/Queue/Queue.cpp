#include <iostream>
#include "Queue.h"

Queue::Queue(){
    enqueueIndex = 0;
    dequeueIndex = 0;
    sizeCount = 0;
    for(int i = 0; i < ARRAY_SIZE; ++i){
        array[i] = 0;
    }
}

void Queue::enqueue(char c){
    if(sizeCount < ARRAY_SIZE){
    array[enqueueIndex] = c;
    std::cout << "入力された値 : " << array[enqueueIndex] << std::endl;
    ++enqueueIndex;
    ++sizeCount;
    enqueueIndex %= ARRAY_SIZE;
    }
}

char Queue::dequeue(){
    char returnValue = array[dequeueIndex];
    std::cout << "取り出された値 : " << array[dequeueIndex] << std::endl; 
    array[dequeueIndex] = 0;
    ++dequeueIndex;
    dequeueIndex %= ARRAY_SIZE;
    if(sizeCount > 0) --sizeCount;
    return returnValue;
}

void Queue::print(){
    int index = dequeueIndex;

    for(int i = 0; i < sizeCount; ++i){
        std::cout << array[index];
        index++;
        index %= ARRAY_SIZE;
    }
    std::cout << std::endl;
}