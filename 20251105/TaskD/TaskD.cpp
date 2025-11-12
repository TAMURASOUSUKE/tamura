#include <iostream>

const int LOOP_SIZE = 100;

int main(){
    for(int i = 1; i <= LOOP_SIZE; ++i){
        bool isFizz = i % 3 == 0;
        bool isBuzz = i % 5 == 0;
        if(isFizz && isBuzz) std::cout << "FizzBuzz";
        else if(isFizz) std::cout << "Fizz";
        else if(isBuzz) std::cout << "Buzz";
        else std::cout << i;
        std::cout << "\n";
    }

    std::cout << std::endl;
    return 0;
}
