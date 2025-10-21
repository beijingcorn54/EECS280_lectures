#include <fstream>
#include<string>
#include<iostream>

using namespace std;

class Triangle{
    private: // Private members cannot be accessed outside the Triangle class
    int angleA;
    int angleB;
    int angleC;

    public:
    int a;
    int b;
    int c;

    // Constructors

    // Assignment inside the constructor body
    Triangle(){ // Default constructor
        a = 1;
        b = 1;
        c = 1;
    }

// Assignment via member initializer list.  REQUIRED if:
    // Your class has a reference member (ex. if this was a data member: int &d)
    // You're using constructor delegation
    // Your class has a non-static const member (ex. if this was a data member: const int c)
    // Your class doesn't have a default constructor
    // For the initialization of base class members
            // EX. Hawk(bool can_fly_in, int age_in, double talon_length_in, bool is_endangered_in, string nativeLand_in):
            //Bird(can_fly_in, age_in), talon_length(talon_length_in), is_endangered(is_endangered_in), nativeLand(nativeLand_in){}
    // Your constructor's parameter name is the same as a data member name
    Triangle(double a_in, double b_in, double c_in): a(a_in), b(b_in), c(c_in){}

    // Delegating constructors: Allows one constructor to call another constructor
    Triangle(double side) // Delegator
    : Triangle(side, side, side){} // Delegatee

    // Destructor: Inverse function of a constructor, it destroys an object (for program safety or storage purposes)
    ~Triangle(){
        cout << "Triangle dtor" << endl;
    }

    // Member function
    void scale(double s){ 
        a *= s;
        b *= s;
        c *= s;
    }
    void print() const{ // const modifier
        cout << "Side lengths: " << a << " " << b << " " << c << endl;
    }
};

class Professor {
    private:
    Triangle favTriangle;

    public:
    string name;
    int students;

    Professor(string name_in, int students_in, int triangle_side_in): name(name_in), students(students_in), favTriangle(triangle_side_in) {}
    Professor(string name_in, int students_in): name(name_in), students(students_in) {}

};

int main(){ // You can only access public members in this driver function

    Triangle t1(1, 2, 3);
    Triangle t2(4); // Triangle where all sides are length 4
    t2.scale(3); // Triangle where all sides are length 12

    Professor p1 = Professor("Bob", 12, 3);
    Professor p2 = Professor("Janet", 10); // Favorite triangle: all sides are length 1 via default constructor

    Professor p3 = p2; // Copy of p2
    Professor p4(p1); // Copy of p1
    p3.name = "Bill";
    p4.name = "Hailey";
}