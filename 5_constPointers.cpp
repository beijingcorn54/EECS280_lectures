#include <utility>
#include<iostream>
using namespace std;

int main(){
// Constant Qualifier (const): Indicates that a variable should not be changed in the code
const int x = 3;
int y = 0;


// CONSTANT QUALIFIER FOR POINTERS
int *const ptr_const_1 = &y;    // This pointer CANNOT be reassigned to a different variable, 
                                // but CAN directly assign its variable to a different value
    *ptr_const_1 = 5;    // OK: Assigns x to 5
    ptr_const_1 = &x;     // ERROR

int const * ptr_const_2 = &y;   // This pointer CAN be reassigned to a different variable, 
                                // but CANNOT directly assign its variable to a different value
    *ptr_const_2 = 5;    // ERROR
    ptr_const_2 = &x;     // OK: the pointer is rebound to x
const int * ptr_const_3 = &y;   // Same way as initializing ptr_const_2


// CONSTANT QUALIFIER FOR REFERENCES: A constant reference must be bound to a constant value
const int &ref_x = x; // OK
const int &ref_y = y; // NO: ref_y is a constant, but  y is NOT a constant

int &ref_x = x; // ERROR: ref_x is NOT a constant, but x is a constant
int &ref_y = y; // OK


}