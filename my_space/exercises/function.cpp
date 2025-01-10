#include <iostream>

int add(int x, int y){
    return x + y;
}

int main(){
    int sum = add(5, 3);
    std::cout << "Sum: " << sum << std::endl;
    return 0;
}