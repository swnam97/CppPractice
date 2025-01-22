#include <iostream>
#include "Battery.h"
using namespace std;

Battery::Battery(): Part(), mMake{"LG Energy Solution"}, mBatteryLevel{100.0} {}
Battery::Battery(string name, double weight, std::string make, double batterylevel): Part(name, weight), mMake{make}, mBatteryLevel{batterylevel} {}
Battery::Battery(const Battery& other): Part(other), mMake{other.mMake}, mBatteryLevel{other.mBatteryLevel} {}
Battery& Battery::operator=(const Battery& other) {
    if (this != &other) {
        mName = other.mName;
        mWeight = other.mWeight;
        mMake = other.mMake;
        mBatteryLevel = other.mBatteryLevel;
    }
    return *this;
}
Battery::~Battery() {};

void Battery::print() {
    cout << "Battery part." << endl;
}

double Battery::getBatteryLevel() {return mBatteryLevel;}

void Battery::consumeBattery() {mBatteryLevel -= 5.0;}

void Battery::chargeBattery() {
    cout << "Current battery level: " << mBatteryLevel << "%" << endl;
    mBatteryLevel = 100.0;
    cout << "The battery is completely charged!" << endl;
}
