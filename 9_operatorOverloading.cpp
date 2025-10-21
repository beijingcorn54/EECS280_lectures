#include <fstream>
#include<string>
#include<iostream>

using namespace std;


class Triangle{
    private:
    int angleA;
    int angleB;
    int angleC;

    public:
    int a;
    int b;
    int c;

    Triangle(): a(1), b(1), c(1) {}
    Triangle(double a_in, double b_in, double c_in): a(a_in), b(b_in), c(c_in){}

    Triangle(double side)
    : Triangle(side, side, side){}

    ~Triangle(){
        cout << "Triangle dtor" << endl;
    }

    void scale(double s){ 
        a *= s;
        b *= s;
        c *= s;
    }
};

// Function Overloading: Same name, but function signature
    // Function Signature: includes parameters and their types, but NOT the return type

int add(int a, int b){
    return a + b;
}
double add(double a, double b){
    return a + b;
}
double add(int a, double b){
    return a + b;
}
double add(double a, int b){
    return a + b;
}

// OVERLOADING OPERATORS ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Expands the capabilities of existing operators in code
    // Output operator overloadig must be declared as a non-member function

double operator+(const Triangle &tri1, const Triangle &tri2){ // Adds the perimeters of 2 triangles
    double a = tri1.a + tri2.a;
    double b = tri1.b + tri2.b;
    double c = tri1.c + tri2.c;
    return (a + b + c);
}

ostream &operator<<(ostream &os, const Triangle &t){ // Remember to use std:: for ostreams if not using namespace std
    os << "Triangle sides: sideA{" << t.a << "}, sideB{" << t.b << "}, sideC{" << t.c << "}";
}

int main(){
    // Function overloading
    cout << add(1, 4) << endl;
    cout << add(-0.23, 2.0) << endl;
    cout << add(1234.234, -987) << endl;

    // Operator overloading
    Triangle t1(1, 2, 3);
    Triangle t2(4);
    double t1_t2 = t1 + t2; // + adds all side lengths of t1 and t2

    cout << t1 << endl; // << prints the sides of t1

}