#include <iostream>
#include <string>

// Base class
class Animal {
protected:
    std::string name; // Protected member can be accessed by derived classes
    // std::string test = "Test!";

public:
    Animal(std::string n) : name(n) {} // Constructor initializes the name

    void eat() const {
        std::cout << name << " is eating." << std::endl; // Common behavior for all animals
    }

    void sleep() const {
        std::cout << name << " is sleeping." << std::endl; // Common behavior for all animals
    }
};

// Derived class: Dog inherits from Animal
class Dog : public Animal {
public:
    Dog(std::string n) : Animal(n) {} // Calls the constructor of the base class

    void bark() const {
        std::cout << name << " says Woof!" << std::endl; // Unique behavior for Dog
    }
};

// Derived class: Cat inherits from Animal
class Cat : public Animal {
public:
    Cat(std::string n) : Animal(n) {} // Calls the constructor of the base class

    void meow() const {
        std::cout << name << " says Meow!" << std::endl; // Unique behavior for Cat
    }
};

int main() {
    Dog dog("Buddy"); // Create a Dog object
    Cat cat("Whiskers"); // Create a Cat object

    dog.eat();    // Inherited from Animal
    dog.sleep();  // Inherited from Animal
    dog.bark();   // Defined in Dog

    cat.eat();    // Inherited from Animal
    cat.sleep();  // Inherited from Animal
    cat.meow();   // Defined in Cat

    return 0;
}
