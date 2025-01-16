#pragma once
#include <string>

class Car
{
// Access specifier: 'protected' is for inheritance. 
protected: 
    std::string mMake;
    std::string mModel;
    int mYear;
    
public:
    Car();       // Default constructor
    Car(std::string make, std::string model, int year);     // Parameterized constructor
    Car(const Car& car);        // Copy constructor
    Car& operator=(const Car& car);     // Copy assignment operator override 
    void drive() const; // Member function (No override here)
    ~Car();     // Destructor
    
};

class SportsCar : public Car
{
protected:
    // A member variable of derived class
    double mTopSpeed;

public:
    SportsCar();    // Default constructor. Called after base class's default constructor.
    SportsCar(std::string make, std::string model, int year, double topspeed);      // Parameterized constructor.
    void drive() const;
};