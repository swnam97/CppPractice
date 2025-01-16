#include <iostream>
#include <string>
#include "Car.h"
using namespace std;

int main() {

    // A base Class instantiating.
    Car car1{"Hyundai", "Genesis", 2021};
    car1.drive();

    // A derived Class instantiating
    SportsCar sportscar1{"Porsche", "911", 2023, 250.0};
    sportscar1.drive();
    return 0;
}
