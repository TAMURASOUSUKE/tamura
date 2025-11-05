#include <iostream>

const int DATA_SIZE = 10;

int main(){
    srand(time(nullptr));
    int data[DATA_SIZE];

    // 乱数の格納
    for(int i = 0; i < DATA_SIZE; ++i){
        data[i] = rand();
    }

    for(int i = 0; i < DATA_SIZE; ++i){
        std::cout << data[i] << "\n";
    }

    std::cout << std::endl;
}