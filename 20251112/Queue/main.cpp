#include <iostream>
#include "Queue.h"

int main(){
    srand(time(nullptr));
    Queue queue;
    bool isDeueue = false; 
    for(char c = 'A'; c <= 'Z'; ++c){
        isDeueue = rand() % 2;
        queue.enqueue(c);
        if(isDeueue){
            queue.dequeue();
            queue.print();
        }
    }

    queue.print();
    return 0;
}