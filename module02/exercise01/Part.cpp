#include <iostream>
#include "Part.h"
using namespace std;

// Orthodox Canonical Form
Part::Part(): mName{"Unknown"}, mWeight{0.0} {};
Part::Part(string name, double weight): mName{name}, mWeight{weight} {};
Part::Part(const Part& other): mName{other.mName}, mWeight{other.mWeight} {};
Part& Part::operator=(const Part& other) {
    if (this != &other) {
        cout << "Copy assignment operator is called from 'Part' class." << endl;
        mName = other.mName;
        mWeight = other.mWeight;
    }
    return *this;
};
Part::~Part() {};

// Additional member functions
void Part::print() {
    cout << "================ Part Info ================" << endl;
    cout << "Name: " << mName << "\nWeight: " << mWeight << endl;
    cout << "========================  ================\n" << endl;
}