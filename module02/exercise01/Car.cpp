#include <iostream>
#include <cmath>
#include <iomanip>
#include "Car.h"
using namespace std;

#define DEG_TO_RAD_RATIO (M_PI/180)               // Macro

// Orthodox Canonical Form
Car::Car() {
    cout << "A new car is just created." << endl;
}
Car::Car(const Car& other): mState{other.mState}, mCarInfo{other.mCarInfo}, mBattery{other.mBattery} {            // 'mWheel{other.mWheel}' is invalid.
    for (int i = 0; i < 4; i++) {
        mWheel[i] = other.mWheel[i];
    }
    cout << "A new car is just created by copy constructor." << endl;
}
Car& Car::operator=(const Car& other) {
    if (this != &other) {
        mState = other.mState;
        mCarInfo = other.mCarInfo;
        mBattery = other.mBattery;
        for (int i = 0; i < 4; ++i) {                // Direct assignment 'mWheel = other.mWheel' is invalid.
            mWheel[i] = other.mWheel[i];
        }
        cout << "A car is just copied by copy assignment operator." << endl;
    }
    return *this;
} 
Car::~Car() {}

// Additional member functions
void Car::printAll() {
    cout << "**************************** Print All ****************************" << endl;
    mState.printState();
    mCarInfo.printCarInfo();

    cout << "================ Parts Info ================" << endl;
    mBattery.print();
    for (int i=0; i < 4; ++i) {
        mWheel[i].print();
        cout << " (" << i+1 << ")" << endl;
    } 
    cout << "============================================" << endl;
    cout << "******************************************************************" << endl;
}

void Car::horn() {
    cout << "Bbang bbang!" << endl; 
}

void Car::translate(double distance) {
    double updated_x = mState.getX() + distance * cos(mState.getThetaDeg() * DEG_TO_RAD_RATIO);
    double updated_y = mState.getY() + distance * sin(mState.getThetaDeg() * DEG_TO_RAD_RATIO);
    mState.updateState(updated_x, updated_y);
    mBattery.consumeBattery();

    cout << fixed << setprecision(2);
    cout << "The car is translated " << distance << " meter." << endl; 
    cout << "Battery level: " << mBattery.getBatteryLevel() << endl; 
}

void Car::rotate(double degree) {
    double updated_theta_deg = mState.getThetaDeg() + degree;
    mState.updateState(updated_theta_deg);
    mBattery.consumeBattery();

    cout << fixed << setprecision(2);
    cout << "The car is rotated " << degree << " degree." << endl; 
    cout << "Battery level: " << mBattery.getBatteryLevel() << endl; 
}

void Car::getWashed() {
    mWashed = true;
    cout << "The car is completely washed!" << endl;
}

void Car::getPose() {
    cout << fixed << setprecision(2);
    cout << "The current pose is [" << mState.getX() << "(m), " << mState.getY() << "(m), " << mState.getThetaDeg() << "(deg)]" << endl; 
}

Battery& Car::getBattery() {return mBattery;}