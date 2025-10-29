#include <iostream>
#include <stdlib.h>

const int ARRAYNUM = 10; // 配列数
const int RIMITLANDOM = 15; // 出る値の制限

int main(){
    srand(time(nullptr)); // 乱数の初期化
    int data[ARRAYNUM];
    int min = 0;
    //int sorted = 0;
    // int currentData = 0;
    // int nextData = 0;

    // 配列の初期化
    for(int i = 0; i < ARRAYNUM; i++){
        data[i] = rand() % RIMITLANDOM;
        std::cout << data[i] << "\n";
    }
    std::cout << std::endl;

    for(int i = 0; i < ARRAYNUM - 1; i++){

        min = i;

       for(int j = i + 1; j < ARRAYNUM; j++){
            if(data[min] > data[j]) {
               min = j;
            }
            int temp = data[i];
            data[i] = data[min];
            data[min] = temp;
        }
     
    }

    // ソート外側のfor文が要素数-1のためすべてcoutに入れられるように外側にfor文を作る
    for(int i = 0; i < ARRAYNUM; i++){
        std::cout << data[i] << "\n";
    }
     std::cout << std::endl;

    return 0;
}





   