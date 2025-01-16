#include <iostream>
#include <string>
#include "SportsCar.h"
using namespace std;

int main() {
    // A base Class instantiating.
    Car car1{"Hyundai", "Genesis", 2021};
    car1.drive();

    // A derived Class instantiating.
    SportsCar sportscar1{"Porsche", "911", 2023, 250.0};
    sportscar1.drive();

    // Checking if the overriding is done well.
    Car* car2 = new SportsCar{"Porsche", "911", 2023, 250.0};
    car2->drive();
    delete car2;

    return 0;
}
