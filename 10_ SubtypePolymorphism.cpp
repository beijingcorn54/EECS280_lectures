#include <fstream>
#include<string>
#include<iostream>

using namespace std;

// Subtype Polymorphism:
    // Pointers from higher subclasses may point to objects of lower subclasses
    // Objects from higher subclasses may reference objects of lower subclasses

    // Upcasts are compliled and safe.  Downcasts are unsafe and do not compile.

// Static type: The data type of the object at compile time
// Dynamic type: The data type of the object at run time

// Virtual Member Function:
    // Only exists for a base class
    // Based on dynamic memory, the correct function from the correct class will be called
// Pure Virtual Function:
    // A virtual member function with no implementation in the base class
    // For abstract classes only
// Abstract Class: A base class that you will not make an object from

// Derived class: Any class derived from a base class (inheritance)
// Subtype:
    // A type of derived class
    // Any object of a subtype can be substituded for objects of its parent class without affecting code functionality

class Food{
    public:
    virtual int f3() = 0; // Pure Virtual Function
};
class Fruit {
    public:
    int f1() { return 1; }
    virtual int f2() { return 10; } // Virtual Member Function
};
class Citrus : public Fruit {
    public:
    int f1() { return 2; }
    int f2() override { return 20; }
};
class Lemon : public Citrus {
    public:
    int f1() { return 3; }
    int f2() override { return 30; }
};

int main() {
// NOT ALLOWED
    // Citrus &cRef = f;
    // Lemon *lPtr = &f;
  Fruit fruit;
  Citrus citrus;
  Lemon lemon;
  Fruit *fPtr = &lemon;
  Citrus *cPtr = &citrus;

  fruit.f2();  // 10
  citrus.f1(); // 2
  fPtr->f1();  // 1
  fPtr->f2();  // 30
  cPtr->f2();  // 20

  cPtr = &lemon;
  cPtr->f1();  // 2
  cPtr->f2();  // 30

}