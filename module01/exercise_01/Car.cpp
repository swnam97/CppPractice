#include <iostream>
#include <string>
using namespace std;

class Car
{
protected: 
    string mMake;
    string mModel;
    int mYear;
    
public:
    Car();       // Default constructor
    Car(string make, string model, int year);     // Parameterized constructor
    Car(const Car& car);        // Copy constructor
    Car& operator=(const Car& car);     // Copy assignment operator override 
    void drive() const;
    ~Car();     // Destructor
    
};

class SportsCar : public Car
{
protected:
    double mTopSpeed;

public:
    SportsCar();
    void drive() const;
};


//////////// Definition of member functions of Car
////////////

Car::Car() : mMake{"Unknown"}, mModel{"Unknown"}, mYear{-1}
{
    cout << "An unknown car is created." << endl;
}

Car::Car(string make, string model, int year) : mMake{make}, mModel{model}, mYear{year}
{
    cout << "A new car is created!" << endl; 
}

Car::Car(const Car& other) : mMake(other.mMake), mModel(other.mModel), mYear{other.mYear}
{
    cout << "The copy constructor is just called." << endl;
}

Car& Car::operator=(const Car& other)
{
    cout << "The copy assignment operator is just called." << endl;

    if (this != &other)
    {
        mMake = other.mMake;
        mModel = other.mModel;
        mYear = other.mYear;
    }
    return *this;
}

void Car::drive() const
{
    cout << "Make: " << mMake << "\nModel: " << mModel << "\nYear: " << mYear << endl;
}

Car::~Car() 
{
    cout << "The car is destroyed." << endl;
}


//////////// Definition of member functions of Sports Car
////////////
void SportsCar::drive() const
{
    Car::drive();
    cout << "\nTop speed: " << mTopSpeed << endl;
}

int main() {
    Car car1;
    Car car2{"Hyundai", "Genesis", 2021};

    SportsCar sportscar1;
    SportsCar sportscar2{""};

}
