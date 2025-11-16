#include <fstream>
#include<string>
#include<iostream>

using namespace std;

class Bird{
    public:
    bool can_fly;
    int age;

    Bird(bool can_fly_in, int age_in): can_fly(can_fly_in), age(age_in){}

    void talk() const{
        cout << "Chirp" << endl;
    }
};

class Chicken: public Bird{ // Inherits public members from Bird class.  Public members of Bird class are also implicitly part of Chicken class
    private:
    bool hen;
    bool meat;

    public:
    double weight;

    Chicken(bool can_fly_in, int age_in, bool hen_in, bool meat_in):
    Bird(can_fly_in, age_in), hen(hen_in), meat(meat_in)
    {}

    void talk() const{ // Overrides the talk() function in Bird (for Chicken objects)
        cout << "Bawk" << endl;
    }
};

class Hawk: public Bird{ // Inherits public members from Bird class.  Public members of Bird class are also implicitly part of Hawk class
    public:
    double talon_length;
    bool is_endangered;
    string nativeLand;

    Hawk(bool can_fly_in, int age_in, double talon_length_in, bool is_endangered_in, string nativeLand_in):
    Bird(can_fly_in, age_in), talon_length(talon_length_in), is_endangered(is_endangered_in), nativeLand(nativeLand_in)
    {}

    void talk() const { 
        if(age > 4){
            cout << "SCREECH" << endl;
        } else{
            Bird::talk(); // If age <= 4 then the Hawk talk() function calls on the Bird talk() function
        }
    }
};

int main(){
    Hawk h_old = Hawk(true, 12, 9.2, false, "North America");
    Hawk h_young = Hawk(true, 2, 9.2, false, "North America");
    Bird b = Bird(true, 9);
    Chicken c = Chicken(b.can_fly, b.age, true, true);

    h_old.talk(); // Calls the Hawk talk() function
    h_young.talk(); // Calls the Bird talk() function
    c.talk();  // Calls the Chicken talk() function
    b.talk();  // Calls the Bird talk() function
}


// g++ 9_inheritance.cpp -o 9_inheritance.exe
// ./9_inheritance.exe