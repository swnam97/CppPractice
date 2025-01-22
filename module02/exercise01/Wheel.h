#pragma once

#include <string>
#include "Part.h"

class Wheel : public Part
{
protected:
    std::string mMake;
    int mDiameter;
    double mPrice;

public:
    // Orthodox Canonical Form
    Wheel();
    Wheel(std::string name, double weight, std::string make, int diameter, double price);
    Wheel(const Wheel& other);
    Wheel& operator=(const Wheel& other);
    ~Wheel();

    // Additional member functions
    void print() override;
};