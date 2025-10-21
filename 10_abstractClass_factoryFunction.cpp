#include <fstream>
#include<string>
#include<iostream>

using namespace std;

// Derived type: Any class derived from a base class (inheritance)
// Subtype: A derived type where anything true in the base class is ALWAYS true for the derived type

// Abstract Class: You will never make an object from this funamental class, but many
// important classes are derived from this class
class Animal{
    public:
    string name;
    int age;

    Animal(string name, int age): name(name), age(age){}

    // Pure virtual functions: Since this is an abstract class, the Animal talk() function
    // will never have to be called, but talk() functions from derived classes will exist
    virtual void talk() const = 0;

};


class Bird: public Animal{
    private:
    bool can_fly;
    bool is_eatible;

    public:
    double weight;

    Bird(string name, int age, bool can_fly, bool is_eatible):
    Animal(name, age), can_fly(can_fly), is_eatible(is_eatible) {}

    void talk() const override{
        cout << "Chirp" << endl;
    }
};

class Bear: public Animal{
    public:
    string nativeLand;
    bool is_dangerous;

    Bear(string name, int age, string nativeLand, bool is_dangerous):
    Animal(name, age), nativeLand(nativeLand), is_dangerous(is_dangerous) {}

    void talk() const override{
        cout << "Grrr" << endl;
    }
};

Animal *animal_factory(const bool is_predator, const int age){
    if(is_predator){
        return new Bear("Generic Bear", age, "North America", true);
        // "new" operator ensures that the created object will exist in
        // dynamic memory, meaning it will still exist outside of the function
    } else{
        return new Bird("Generic Bear", age, true, true);
    }
}

int main(){
    Bear Jamie = Bear("Jamie", 10, "North America", true);
    Bird Tenders = Bird("Tenders", 2, false, true);

    Animal *aPtr = &Jamie;
    aPtr->age = 11;
    aPtr->talk();

    // Calling the factory function
    Animal *animalPtr = animal_factory(true, 2);
    animalPtr = animal_factory(false, 0);
    delete animalPtr;
    // good practice to use "delete" operator once the pointer's use has ended, 
    // since the animal_factory() function uses the "new" operator
}
