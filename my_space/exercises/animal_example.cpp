#include <iostream>
using namespace std;
#include <vector>

class Animal {
public:
    virtual ~Animal() { // Virtual destructor
        cout << "Animal destroyed" << endl;
    }
};

class Dog : public Animal {
public:
    ~Dog() {
        cout << "Dog destroyed" << endl;
    }

    int num = 1;
};

int main() {
    Animal d = Dog();
    // Dog* animal = &d;
    // Dog d = Dog();
    Animal* animal = new Dog();
    float f = 1.0;
    // cout << animal->num;
    delete animal; // Proper cleanup: Dog's destructor is called first, then Animal's
    return 0;
}