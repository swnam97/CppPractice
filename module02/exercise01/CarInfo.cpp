#include <iostream>
#include "CarInfo.h"
using namespace std;

// Orthodox Canonical Form
CarInfo::CarInfo(): mMake{"Hyundai"}, mModel{"Sonata"}, mYear{2021} {}
CarInfo::CarInfo(string make, string model, int year): mMake{make}, mModel{model}, mYear{year} {}
CarInfo::CarInfo(const CarInfo& other): mMake{other.mMake}, mModel{other.mModel}, mYear{other.mYear} {};
CarInfo& CarInfo::operator=(const CarInfo& other) {
    if (this != &other) {
        cout << "Copy assignment operator is called from 'CarInfo' class." << endl;
        mMake = other.mMake;                /////////////////// yh!
        mModel = other.mModel;
        mYear = other.mYear;
    }
    return *this;
};
CarInfo::~CarInfo() {};

// Additional member functions
void CarInfo::printCarInfo() {
    cout << "================ Car Info ==================" << endl;
    cout << "Make: " << mMake << "\nModel: " << mModel << "\nYear: " << mYear << endl;
    cout << "============================================\n" << endl;
}