#include <iostream>
#include "Wheel.h"
using namespace std;

Wheel::Wheel(): Part(), mMake{"Nexen"}, mDiameter{17}, mPrice{20.0} {}
Wheel::Wheel(string name, double weight, std::string make, int diameter, double price): Part(name, weight), mMake{make}, mDiameter{diameter}, mPrice{price} {}
Wheel::Wheel(const Wheel& other): Part(other), mMake{other.mMake}, mDiameter{other.mDiameter}, mPrice{other.mPrice} {}
Wheel& Wheel::operator=(const Wheel& other) {
    if (this != &other) {
        mName = other.mName;
        mWeight = other.mWeight;
        mMake = other.mMake;
        mDiameter = other.mDiameter;
        mPrice = other.mPrice;
    }
    return *this;
}
Wheel::~Wheel() {};

void Wheel::print() {
    cout << "Wheel part.";
}

