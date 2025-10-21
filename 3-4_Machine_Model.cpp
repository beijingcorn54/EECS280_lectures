#include <iostream>
#include <vector>
using namespace std;


// Pass by pointer - The pointers for variables, or variable addresses, are passed into the function
vector<int> pair_pbr(int *x, int *y){
    return {x, y}; // Ex. (ptr1, ptr2} is returned
}


// Pass by reference - The original variable is passed into the function
vector<int> pair_pbr(int &x, int &y){
    return {x, y}; // Ex. (temp_val, my_var} is returned
}


// Pass by value - The value of the argument is passed into the function
vector<int> pair_pbr(int x, int y){
    return {x, y}; // Ex. (3, 7} is returned
}

int main(){
    int x = 10;
    int y = 9;
    x = y; // x = 9

    // Addressses (&): The machine code address of a variable
    int &z = x; // z and x are now stored at the same address in the computer.
                // z and x are the same variable, z==x is always true.
                // z = 9
    z = 17; // z = 17, x = 17    


    // Pointer: Dereferences a variable;  Gets a variable from an address
        // Referencing (&): Setting a pointer to store a variable
        // Dereferencing (*): Accessing the variable that a pointer stores
    // int *ptr = nullptr is a "Null Pointer"
    int a = 3;
    int b = 4;
    int *ptr = &a;          // The address of ptr is 0x101: &ptr = 0x101
                            // The value of ptr is the address of a: ptr = 0x111
                            // The value of a, held by ptr, is 3: *ptr = 3
    int ** ptr_ptr = &ptr;  // The address of ptr_ptr is 0x001: &ptr_ptr = 0x001
                            // The value of ptr_ptr is the address of ptr: ptr_ptr = 0x101
                            // The value of ptr, held by ptr_ptr, is 3: *ptr_ptr = 0x111
    ptr = &b;               // ptr is now bound to b instead of a
    int c = *ptr;           // c = 4
}

