#pragma once

#include <string>

/// @brief Represents a base car class. 
class Car
{
protected: 
    std::string mMake;
    std::string mModel;
    int mYear;
    
public:
    // Declarations of member functions
    Car();       // Default constructor
    Car(std::string make, std::string model, int year);     // Parameterized constructor
    Car(const Car& car);        // Copy constructor
    Car& operator=(const Car& car);     // Copy assignment operator override 
    virtual void drive() const; // Virtual function for abstraction
    ~Car();     // Destructor
};

