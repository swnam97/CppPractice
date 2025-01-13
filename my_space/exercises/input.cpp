#include <iostream>
#include <string>
using namespace std;

int main() {
    int age;
    string name;

    cout << "Enter your age: ";
    cin >> age;

    cin.ignore();

    cout << "Enter your name: ";
    // cin >> name;
    getline(cin, name);

    cout << "Age: " << age << endl;
    cout << "Name: " << name << endl;
}