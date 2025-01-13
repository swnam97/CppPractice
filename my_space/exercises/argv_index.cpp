#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char* argv[]) {
    // Count
    cout << "Count: " << argc << endl;

    // file name
    cout << argv[0] <<endl;

    // referencing
    cout << "1st string: " << argv[1] << endl;
    cout << "Length of 1st string: " << strlen(argv[1]) << endl;
    cout << "1st string from 2nd char: "<< argv[1] + 1 << endl;

    // dereferencing 
    cout << "1st char of 1st string: " << *(argv[1]) << endl;
    cout << "2nd char of 1st string: " << *(argv[1] + 1) << endl;

    cout << "1st char of 2nd string: " << *(argv[2]) << endl;
    cout << "2nd char of 2nd string: " << *(argv[2] + 1) << endl;

    // raw memory address
    cout << "Memory address of 1st char of 1st string" << (void*)argv[1] << endl;
    cout << "Memory address of 2nd char of 1st string" << (void*)(argv[1] + 1) << endl;

}