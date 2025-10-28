#include <fstream>
#include<string>
#include<iostream>

using namespace std;

class apple{
    private:
    int x;
    int y;

    public:

    // Assignment inside the constructor body
    apple(){ // Default constructor
        x = 1;
        y = 2;
    }
    // Assignment via member initializer list
    apple(int x_in, int y_in): x(x_in), y(y_in){}

    // Destructor: Inverse  of a constructor, it destroys an object (for program safety or storage purposes)
    ~apple(){
        cout << "apple dtor" << endl;
    }
};

// Member initializer list are REQUIRED if:
    // 1. Class has a reference member
    // 2. Class has a non-static const member
    // 3. Class doesn't have a default constructor
    // 4. Constructor's parameter name is the same as a data member name
    // 5. Constructor Delegation:  Allows one constructor to call another constructor

class banana{
    private:
    int &x; // 1
    const int y; // 2

    public: // 3
    banana(int &x, int y): x(x), y(y){} // 4

    ~banana(){
        cout << "banana dtor" << endl;
    }
};

class cherry{ // 5
    private:
    int x;
    int y;
    int z;

    public:
    cherry(int x, int y, int z): x(x), y(y), z(z) {}

    cherry(int x): // Delegator
    cherry(x, x, x){} // Delegatee

    ~cherry(){
        cout << "cherry dtor" << endl;
    }
};