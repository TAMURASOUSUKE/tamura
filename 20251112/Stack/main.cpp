#include "Stack.h"
#include <iostream>

int main(void){
    srand(time(nullptr));
    bool isPop = false;
    
    Stack stack;
    for(char c = 'a'; c <= 'z'; ++c){
        stack.push(c);
    }

    stack.print();

    return 0;
}