#include <iostream>
#include <string>

class Person {
public: 
    std::string name;
    int age;

    void introduce(){
        std::cout << "Hi, I'm " << name << " and I'm " << age << " years old." << std::endl;
    }
};

int main() {
    Person person;
    person.name = "Seungwon Nam";
    person.age = 29;
    person.introduce();

    return 0;
}

