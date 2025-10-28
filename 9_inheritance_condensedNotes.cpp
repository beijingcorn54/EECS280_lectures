#include<string>
#include<iostream>

using namespace std;

class Animal{
    private:
    // If you don't intend to create an Animal object, you must leave this blank
    string species;

    public:
    bool is_predator;
    string name;

    Animal(string species_in, bool is_predator_in, string name_in): species(species_in), is_predator(is_predator_in), name(name_in) {}
    Animal(bool is_predator_in, string name_in): is_predator(is_predator_in), name(name_in) {}
    ~Animal(){}

    void talk(){
        cout << "rawr" << endl;
    }
};
// Inherited Class: Inherits public members from Animal class
class Bird: public Animal{
    private:
    bool can_fly;

    public:
    Bird(bool is_predator_in, string name_in, bool can_fly_in): Animal(is_predator_in, name_in), can_fly(can_fly_in){}
    ~Bird(){}

    void talk(){
        cout << "chirp" << endl;
    }
};
class Cat: public Animal{
    private:
    bool is_pet;

    public:
    Cat(string name_in, bool is_pet_in): Animal(true, name_in), is_pet(is_pet_in){}
    ~Cat(){}

    void talk(){
        if(is_pet){
            cout << "meow" << endl;
        } else{
            Animal::talk(); // Calling a base class' function implementation
        }
    }
};

int main(){
    Animal jeff("Turtle", false, "Jeff");
    Bird victor(true, "Victor", true);
    Cat max = Cat("Max", true);
    Cat mittens = Cat("Max", false);

    jeff.talk(); // rawr
    victor.talk(); // chirp
    max.talk(); // meow
    mittens.talk(); // rawr
}
