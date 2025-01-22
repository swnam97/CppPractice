#pragma once

#include <string>

// Base class
class Part
{
protected:
    std::string mName;
    double mWeight;

public:
    // Orthodox Canonical Form
    Part();
    Part(std::string name, double weight);
    Part(const Part& other);
    Part& operator=(const Part& other);
    ~Part();

    // Additional member functions
    virtual void print();
};