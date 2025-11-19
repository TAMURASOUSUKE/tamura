#include <iostream>

const int DATA_SIZE = 11;
int main(){
    srand(time(nullptr));
    // 配列の初期化
    int data[DATA_SIZE];
    int result = -1;
    int target = 5;

    for(int i = 0; i < DATA_SIZE; ++i){
        data[i] = i;
    }

    for(int i = 0; i < DATA_SIZE; ++i){
        int random = rand() % DATA_SIZE;
        int temp = data[i];
        data[i] = data[random];
        data[random] = temp;
    }

    for(int i = 0; i < DATA_SIZE; ++i){
        if(data[i] == target) {
            result = i;
            break;
        }
    }

    std::cout << target << "のインデックスは" << result << "です。" << std::endl;

    return 0;
}