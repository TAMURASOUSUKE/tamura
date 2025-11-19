#include <iostream>
#include "Stack.h"

Stack::Stack(){
    index = 0;
    for(int i = 0; i < ARRAY_SIZE; ++i){
        array[i] = 0;
    }
}

void Stack::push(char c){
    array[index] = c;
    std::cout << "追加した値 : " << c << "\n";
    index++;
}

char Stack::pop(){
    int popIndex = --index;
    char temp = array[popIndex];
    array[popIndex] = 0;
    return temp;
}

void Stack::print(){
    for(int i = 0; i < index; ++i){
        std::cout << array[i];
    }

    std::cout << std::endl;
}