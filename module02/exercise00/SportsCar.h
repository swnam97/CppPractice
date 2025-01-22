#pragma once

#include <string>
#include <memory>
#include "Car.h"

/// @brief Represents a derived class from 'Car' class.
class SportsCar : public Car
{
protected:
    // An additional member variable of derived class.
    double mTopSpeed;

public:
    // Declarations of member functions
    SportsCar();
    SportsCar(std::string make, std::string model, int year, double topspeed);
    void drive() const override;
};