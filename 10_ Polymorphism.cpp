#include <fstream>
#include<string>
#include<iostream>

using namespace std;

// Subtype Polymorphism:
// A pointer/reference to an object of a general class can be repointed to an object of a derived/sub class

// Static pointer: what the pointer explicitly was initialized to
// Dynamic pointer: what the pointer is actually pointing to currently

// Virtual function: Allows the correct function from the correct class to be
                //   called based on the dynamic pointer instead of the static pointer

class Fruit {
public:
    int f1() { // NO OVERRIDE, referrs to the static pointer type
        return 1;
    }
    virtual int f2() { // Virtual function established in the base class
        return 2; 
    }
};

class Citrus : public Fruit {
public:
    int f1() { // NO OVERRIDE, referrs to the static pointer type
        return 3;
    }
    int f2() override { // Refers to the dynamic pointer type
        return 4;
    }
};

class Lemon : public Citrus {
public:
    int f1() { // NO OVERRIDE, referrs to the static pointer type
        return 5;
    }
    int f2() override { // Refers to the dynamic pointer type
        return 6;
    }
};


int main(){
    Fruit f;
    Citrus c;
    Lemon l;

    // Pointers from higher subclasses are allowed to point to objects of lower subclasses
    Fruit *fPtr = &l;
    fPtr = &c;
    Citrus *cPtr = &c;

    // Objects from higher subclasses are allowed to referece objects of lower subclasses
    Fruit &fRef = l;

    // NOT ALLOWED
        // Citrus &cRef = f;
        // Lemon *lPtr = &f;

    // Due to virtual functions and overrides, the correct f1() and f2() function is always called
    
    cout << f.f2() << endl;  // 2
    cout << c.f1() << endl; // 3
    cout << fPtr->f1() << endl;  // 1 - No function overrride, static pointer used
    cout << fPtr->f2() << endl;  // 6 - Function override
    cout << cPtr->f2() << endl;  // 4 - Function override
}