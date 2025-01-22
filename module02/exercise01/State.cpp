#include <iostream>
#include <cmath>
#include "State.h"
using namespace std;

// Orthodox Canonical Form
State::State(): mX{0}, mY{0}, mTheta{0.0} {};
State::State(double x, double y, double theta): mX{x}, mY{y} {                              
    mTheta = setThetaRange(theta);
};
State::State(const State& other): mX{other.mX}, mY{other.mY}, mTheta{other.mTheta} {};
State& State::operator=(const State& other) {
    cout << "Copy assignment operator is called from 'State' class." << endl;
    if (this != &other) {
        mX = other.mX;                
        mY = other.mY;
        mTheta = other.mTheta;
    }
    return *this;
};
State::~State() {};

// Additional member functions
void State::printState() {
    cout << "================ State Info ================" << endl;
    cout << "x: " << mX << " (m)" << "\ny: " << mY << " (m)" << "\nTheta: " << mTheta << " (deg)"<< endl;
    cout << "============================================\n" << endl;
}

double State::getX() { return mX; }

double State::getY() { return mY; }

double State::getThetaDeg() { return mTheta; }

double State::setThetaRange(double degree) {
    while (!(degree >= 0.0 && degree < 360.0)) {                                 // (!!) Warning - Comparion between floating-point values is not recommended ...
        if (degree < 0) 
            degree += 360.0;
        else if (degree >= 360.0) 
            degree -= 360.0;
    }
    return degree;
}

void State::updateState(double updated_x, double updated_y) {
    mX = updated_x;
    mY = updated_y;
}

void State::updateState(double updated_theta_deg) {
    mTheta = setThetaRange(updated_theta_deg);
}