#include "Stack.h"
#include <iostream>

int main(void){
    srand(time(nullptr));
    bool isPop = false;
    
    Stack stack;
    for(char c = 'a'; c <= 'z'; ++c){
        isPop = rand() % 2;
        stack.push(c);

        if(isPop){
            std::cout << "取り出した値 : " << stack.pop() << "\n";
            stack.print();
        }
    }

    stack.print();

    return 0;
}