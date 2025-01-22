#pragma once

#include <memory>
#include "State.h"
#include "CarInfo.h"
#include "Wheel.h"
#include "Battery.h"

class Car
{
private:
    State mState;
    CarInfo mCarInfo;
    Wheel mWheel[4];
    Battery mBattery;
    bool mWashed = false;

public:
    // Orthodox Canonical Form
    Car();
    Car(const Car& car);
    Car& operator=(const Car& car); 
    ~Car();

    // Additional member functions
    void printAll();
    void horn();
    void translate(double distance);
    void rotate(double angle);
    void getWashed();
    void getPose();
    Battery& getBattery();
};

