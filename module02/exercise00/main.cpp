#include <iostream>
#include <string>
#include <memory>
#include "SportsCar.h"
using namespace std;

int main() {
    // Smart pointers
    unique_ptr<SportsCar> sportscar_u = make_unique<SportsCar>("Porsche", "Taycan", 2022, 270.0);           // Type 1) std::unique_ptr
    shared_ptr<SportsCar> sportscar_s1 = make_shared<SportsCar>("Porsche", "Taycan", 2022, 270.0);           // Type 2) std::shared_ptr
    
    {
        // new and delete
        SportsCar* sportscar_1 = new SportsCar("Porsche", "911", 2023, 250.0);
        delete sportscar_1;      // If this pointer instance isn't deleted manually, the memory leaking will happen after this scope because we lose the pointer to deallocate the object.
        // At this point, the pointer 'sportscar_1' is a dangling pointer
        sportscar_1 = nullptr;       // For safety, the dangling pointer should be reset to nullptr after deletion

        // Shared pointer
        shared_ptr<SportsCar> sportscar_s2 = sportscar_s1;        
        cout << "\nUse count of shared pointer in the scope: " << sportscar_s1.use_count() << endl;         // Print 2 ==> It means that two pointers are sharing the ownership of the object.
    }
    cout << "Use count of shared pointer after the scope: " << sportscar_s1.use_count() << endl;            // Print 1 ==> After the scope, the number of shared ownership is decreased, because the destructor of sportscar_s1 is called.
    return 0;
}
