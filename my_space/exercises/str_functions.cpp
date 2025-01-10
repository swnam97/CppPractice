#include <iostream>
#include <string>
using namespace std;

int main() {

    // 1. Initialization
    string str = "Hello, I'm Seungwon.";
    cout << "Original String: " << str << endl;

    // 2. Lengh, Size (length, size 둘 다 같음)
    cout << "Length: " << str.length() << endl;
    cout << "Size: " << str.size() << endl;

    // 3. Add string (문자열 추가. append, +=)
    str.append(" How are you?");
    cout << "After append: " << str << endl;

    str += " I'm good.";
    cout << "After += : " << str << endl;

    // 4. Get a substring (substr)
    string subStr1 = str.substr(0,5);
    string subStr2 = str.substr(7,3);
    cout << "Substr 1: " << subStr1 << endl;
    cout << "Substr 2: " << subStr2 << endl;

    // 5. Compare between strings (compare)
    string compareStr = "Hello";
    if (str.compare(0, 5, compareStr) == 0){
        cout << "The first 5 characters => " << compareStr << endl;
    }

    // 6. 

    return 0;

}