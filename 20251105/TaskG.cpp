#include <iostream>
const int DATA_SIZE = 100;
const int RANDOM_NUM = 101;
int main(){
    srand(time(nullptr));
    int data[DATA_SIZE];
    int target = 50;
    int result = -1;
    int left = 0;
    int right = DATA_SIZE - 1;
    for(int i = 0; i < DATA_SIZE; ++i){
        data[i] = rand() % RANDOM_NUM;
    }

    
    // ソート
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

    for(int i = 0; i < DATA_SIZE; ++i){
        std::cout << data[i] << std::endl;
    }

    while(left < right){
        int mid = (left + right) / 2;
        if(data[mid] == target){
            result = mid;
            break;
        }

        if(data[mid] < target) {
            left = mid + 1;
        }
        else{
            right = mid;
        }
    }

    if(result >= 0) std::cout << target << "のインデックスは" << result << "です。" << "\n";
    else std::cout << target << "は見つかりませんでした。" << "\n";
    
    std::cout << std::endl;
    return 0;
}