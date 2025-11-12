#include <iostream>

const int DATA_SIZE = 100;
int main(){
    srand(time(nullptr));
    int data[DATA_SIZE];
    // 乱数の初期化
    for(int i = 0; i < DATA_SIZE; ++i){
        data[i] = rand();
    }

    for(int i = 0; i < DATA_SIZE; ++i){
        for(int j = DATA_SIZE -1; j >= i + 1; --j){
            int valueA = data[i];
            int valueB = data[j];
            if(valueA > valueB){
                int max = valueA;
                int min = valueB;
                data[i] = min;
                data[j] = max;
            }
        }
    }


    // 出力
    for(int i = 0; i < DATA_SIZE; ++i){
        std::cout << data[i] << "\n";
    }

    std::cout << std::endl;

    return 0;
}