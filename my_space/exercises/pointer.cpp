#include <iostream>

using namespace std;

void PointerChecker(int *ptr)
{
    if (ptr)
        cout << "You passed " << ptr << endl;
    else
        cout << "you passed a null pointer." << endl;
}

int main() {

    // Pointer
    cout << "******** Pointer ********" << endl;
    int *ptr1;
    int *ptr2;
    int num(3);
    ptr1 = &num;

    cout << "Number: " << num << endl;
    cout << "Memory address: " << ptr1 << endl;

    // Null Pointer
    cout << "\n" << "******** Null Pointer ********" << endl;
    ptr2 = nullptr;

    PointerChecker(ptr1);
    PointerChecker(ptr2);

    // Pointer and Array
    cout << "\n" << "******** Pointer and Array ********" << endl;
    int array[5] = {1, 3, 5, 7, 9};
    ptr1 = array;

    cout << "The array's address is: " << array << endl;                // "int[5]" type but decays to "int*"
    cout << "The first element's address is: " << &array[0] << endl;    // "int* type

    cout << "\nDereferencing array: " << *array << endl;
    cout << "Dereferencing &array[0]: " << *(&array[0]) << endl;

    cout << "\nSize of array: " << sizeof(array) << endl;
    cout << "Size of Pointer: " << sizeof(ptr1) << endl;

    // Pointer arithmetic and array indexing
    cout << "\n" << "******** Pointer arithmetic and array indexing ********" << endl;
    int value = 7;
    long long value_ll = 9LL;
    int *ptr3 = &value;
    long long *ptr4 = &value_ll;

    cout << "Size of integer: " << sizeof(value) << endl;
    cout << ptr3 << endl;
    cout << ptr3 + 1 << endl; // + 4
    cout << ptr3 + 2 << endl; // + 4
    cout << ptr3 + 3 << endl; // + 4

    cout << "\nSize of long long integer: " << sizeof(value) << endl;
    cout << ptr4 << endl;
    cout << ptr4 + 1 << endl; // + 8
    cout << ptr4 + 2 << endl; // + 8
    cout << ptr4 + 3 << endl; // + 8

    // Pointer and const
    cout << "\n" << "******** Pointer and const ********" << endl;
    const int value1 = 5;
    int value2 = 5;
    const int *ptr5 = &value1;
    const int *ptr6 = &value2;      // still okay,

    // value1 = 2;  It's illegal to change the constant variable.
    value2 = 3;
    // *ptr6 = 2;  It's illegal to change the value through the const pointer.


    return 0;

}