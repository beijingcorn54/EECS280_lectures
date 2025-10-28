#include <utility>
#include<iostream>
using namespace std;

int main(){
// Values: A variable's value cannot change
const int x = 3;
int y = 0;

// Pointers
    // 1. Constant Pointer: The pointer cannot be 
    // reassigned, but its pointed value can change
    int * const ptr_constp = &y;
    *ptr_constp = 10;

    // 2. Pointer to a Constant: The pointer can be 
    // reassigned, but its pointed value cannot change
    int const * ptr_ptr_to_const_a = &x;
    const int * ptr_ptr_to_const_b = &x;
    ptr_ptr_to_const_a = &y;
    
// References: A constant reference must be 
// bound to a constant value
const int &ref_x = x;

int &ref_x = x;         // ERROR: ref_x is NOT a constant, but x is a constant
const int &ref_y = y;   // SHOULD NOT DO: ref_y is a constant, but  y is NOT a constant

}