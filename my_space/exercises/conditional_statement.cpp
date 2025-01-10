#include <iostream>

int main(){
    int number = 10;
    if (number > 0){
        std::cout << "Positive number!" << std::endl;
    }
    else if (number==0) {
        std::cout << "Zero!" << std::endl;
    }
    else {
        std::cout << "Negative number!" << std::endl;
    }

    return 0;
}