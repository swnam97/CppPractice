#pragma once

#include <string>

class CarInfo
{
private:
    std::string mMake;
    std::string mModel;
    int mYear;

public:
    // Orthodox Canonical Form
    CarInfo();
    CarInfo(std::string make, std::string model, int year);
    CarInfo(const CarInfo& carinfo);
    CarInfo& operator=(const CarInfo& carinfo);
    ~CarInfo();

    // Additional member functions
    void printCarInfo();
};