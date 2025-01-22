#include <string>
#include <iostream>
#include "SportsCar.h"
using namespace std;

///////////////////////////////////////////////////
//// Definition of member functions for Sports Car
SportsCar::SportsCar() : mTopSpeed{-1.0} {
    cout << "And this is a sports car." << endl;
}

SportsCar::SportsCar(string make, string model, int year, double topspeed)
: Car{make, model, year}, mTopSpeed{topspeed} {
    cout << "And this is a sports car." << endl;
}

void SportsCar::drive() const {
    Car::drive();
    cout << "Top speed: " << mTopSpeed << endl;
}