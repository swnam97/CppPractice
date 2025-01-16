#include <iostream>
#include <string>
using namespace std;

////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////
class Car
{
private: 
    string mName;
    double mSpeed;
    
public:
    Car();       // Default constructor
    Car(string name, double speed);     // Parameterized constructor
    Car(const Car& car);        // Copy constructor
    Car& operator=(const Car& car);     // Copy assignment operator override 
    void display();     // Member function
    ~Car();     // Destructor
};

Car::Car() : mName{"Unknown"}, mSpeed{-1.0} {}

Car::Car(string name, double speed) : mName{name}, mSpeed{speed} {
    cout << "The car's name is " << name << " and it's current speed is " << speed << "km." << endl;
}

Car::Car(const Car& other) : mName(other.mName), mSpeed(other.mSpeed) {
    cout << "The copy constructor is called." << endl;
}

Car& Car::operator=(const Car& other) {
    cout << "The copy assignment operator is just called." << endl;

    if (this != &other)
    {
        mName = other.mName;
        mSpeed = other.mSpeed;
    }
    return *this;
}

void Car::display() {
    cout << "Car name: " <<  mName << "\n" << "Car speed: " << mSpeed << endl;
}

Car::~Car() {
    cout << "The " << mName << " is destroyed." << endl;
}

////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////

int main() {
    Car car1;                       // Calls default constructor
    Car car2{"Genesis", 80.0};      // Calls parameterized constructor

    car1.display();
    car2.display();
    cout << "\n";

    Car car3 = car2;        // Calls copy constructor
    car1 = car2;        // Calls copy assignment operator
    car1.display();
    car3.display();

    // cout << "\nThe memory address of car1: " << &car1 << endl;
    // cout << "The memory address of car2: " << &car2 << endl;
    // cout << "The memory address of car3: " << &car3 << endl;        // All addresses are different because they're just copied.

    // cout << "\nBefore calling destructors," << endl;
}