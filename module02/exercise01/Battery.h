#pragma once

#include <string>
#include "Part.h"

class Battery : public Part
{
protected:
    std::string mMake;
    double mBatteryLevel;

public:
    // Orthodox Canonical Form
    Battery();
    Battery(std::string name, double weight, std::string make, double batterylevel);
    Battery(const Battery& other);
    Battery& operator=(const Battery& other);
    ~Battery();

    // Additional member functions
    void print() override;
    double getBatteryLevel();
    void consumeBattery();
    void chargeBattery();
};