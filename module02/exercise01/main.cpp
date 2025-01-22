#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Car.h"
using namespace std;

void carWash(const std::shared_ptr<Car> car);
void carCharge(const std::shared_ptr<Car> car);


int main() {
    // Variables for an input command.
    string input;
    string word;
    vector<string> words;
    
    // Initialize Car and print all information.
    auto car = std::make_shared<Car>();
    car->printAll();

    cout << "A car is ready to move!" << endl;
    cout << "Enter any command for car's motion. (e.g. translate 1  /  rotate 45  /  state  /  horn  /  stop) " << endl;
    while (true) {
        // Get input command.
        cout << ">> ";
        getline(cin, input);
        istringstream stream(input);

        // Separate the command.
        words.clear();
        while (stream >> word) {
            words.push_back(word);
        }

        // Several modes.
        if (words[0] == "translate") 
            car->translate(stod(words[1]));
        else if (words[0] == "rotate") 
            car->rotate(stod(words[1]));
        else if (words[0] == "state") 
            car->getPose();
        else if (words[0] == "horn") 
            car->horn();
        else if (words[0] == "wash")
            carWash(car);
        else if (words[0] == "charge")
            carCharge(car);
        else if (words[0] == "stop") {
            cout << "The car stops." << endl;
            std::exit(0);
        }
        else
            cout << "Invalid command." << endl;
        // cout << "Use count of shared pointer (1): " << car.use_count() << endl;
    }
    return 0;
}

void carWash(const std::shared_ptr<Car> car) {
    car->getWashed();
    // cout << "Use count of shared pointer (2): " << car.use_count() << endl;             // Print 2
}

void carCharge(const std::shared_ptr<Car> car) {
    car->getBattery().chargeBattery();
    // cout << "Use count of shared pointer (3): " << car.use_count() << endl;             // Print 2
}