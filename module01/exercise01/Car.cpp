#include <string>
#include <iostream>
#include "Car.h"
using namespace std;

///////////////////////////////////////////////////
//// Definition of member functions for Car class
Car::Car() : mMake{"Unknown"}, mModel{"Unknown"}, mYear{-1} {
    cout << "An unknown car is created!" << endl;
}

Car::Car(string make, string model, int year) : mMake{make}, mModel{model}, mYear{year} {
    cout << "A new car is created!" << endl; 
}

Car::Car(const Car& other) : mMake(other.mMake), mModel(other.mModel), mYear{other.mYear} {
    cout << "The copy constructor is just called." << endl;
}

Car& Car::operator=(const Car& other) {
    cout << "The copy assignment operator is just called." << endl;

    if (this != &other)
    {
        mMake = other.mMake;
        mModel = other.mModel;
        mYear = other.mYear;
    }
    return *this;
}

void Car::drive() const {
    cout << "Make: " << mMake << "\nModel: " << mModel << "\nYear: " << mYear << endl;
}

Car::~Car()  {
    cout << "The car is destroyed." << endl;
}


///////////////////////////////////////////////////
//// Definition of member functions for Sports Car
SportsCar::SportsCar() : mTopSpeed{-1.0} {
    cout << "And this is a sports car." << endl;
}

SportsCar::SportsCar(string make, string model, int year, double topspeed)
: Car{make, model, year}, mTopSpeed{topspeed} {
    cout << "And this is a sports car." << endl;
}

void SportsCar::drive() const {     // No override here. Just used function hiding.
    Car::drive();
    cout << "Top speed: " << mTopSpeed << endl;
}