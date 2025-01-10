#include <iostream>

using namespace std;

int main() {
    // 1. 'for' loop
    cout << "Using for loop: " << endl;

    for (int i = 1; i<=5; ++i) {
        cout << i << " ";
    }

    cout << endl;

    // 2. 'while' loop
    cout << "Using while loop: " << endl;
    int j = 5;
    while (j >= 1) {
        cout << j << " ";
        j--; 
    }
    
    cout << endl;

    // 3. do-while loop
    cout << "Using do-while loop: " << endl;
    // int k = 1;
    do {
        cout << j << " ";
        j++; 
    } while (j <= 5);

    return 0;
}