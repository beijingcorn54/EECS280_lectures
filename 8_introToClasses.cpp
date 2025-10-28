#include <fstream>
#include<string>
#include<iostream>

using namespace std;

class Triangle{
    private: // Private members cannot be accessed by any variable/function call outside the class
    int angle = 0;

    public: // Public members can be accessed by any variable/function call
    int a;
    int b;
    int c;

    Triangle(){a = 1; b = 1; c = 1;}
    Triangle(double a_in, double b_in, double c_in): a(a_in), b(b_in), c(c_in){}
    Triangle(double side): Triangle(side, side, side){}

    ~Triangle(){
        cout << "Triangle dtor" << endl;
    }

    // Member functions
    void increase_angle(double x){ 
        angle += x;
    }
    void scale(double s){ 
        a *= s;
        b *= s;
        c *= s;
    }
    // Const modifier for member function: 
        // Asserts that no member variables can be changed
        // Comes right before the {}
    void print() const{
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
    ~Professor(){}
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