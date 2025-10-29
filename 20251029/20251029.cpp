#include <iostream>
#include <stdlib.h>

const int ARRYNUM = 10;

int main(){
    srand(time(nullptr)); // 乱数の初期化
    int arrys[ARRYNUM];

    for(int i = 0; i < ARRYNUM; i++){
        arrys[i] = rand() % 10;
        std::cout << arrys[i] << "\n";
    }
    std::cout << std::endl;

    return 0;
}