#include <iostream>
#include <vector>
using namespace std;

// Addresses, Pointers, and References
    // Address(&): The address of a value in machine code
    // Reference(&var_name): An alias to a value
    // Pointer(dataType * stuffHere): A value that happens to be an address


// Pass by pointer
    // You can modify what has been passed into the functions
    // DANGER:
        // Can change data 
void pbp(int *x, int *y){
    *x = 3;
    *y = 2;
}

// Pass by reference
    // You can modify what has been passed into the functions
    // DANGER:
        // Can change data
void pbr(int &x, int &y){
    x = 3;
    y = 2;
}


// Pass by value
    // Values are copied into the functions
    // You cannot modify anything outside of the function scope
    // DANGER:
        // x and y are too big
int pbv(int x, int y){
    return (x + y);
}

int main(){
    int x = 10;
    int y = 9;
    int z = 3;
    
    pbp(&x, &y);
    pbr(x, y);
    int z = pbv(x,y);

    // References .//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.
    int &z = x; // z and x are now stored at the same address in the computer.
                // z==x is always true.
    z = 17;     // z = 17, so x = 17
    z += 2;     // z += 2, so x += 2

    // Pointers .//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.
    int *ptr_a = &x;        // ptr_a stores the address of x
    ptr_a;  // Accesses the address of x
    *ptr_a; // Accesses the value of x (dereferences the pointer)
    int *ptr_b = &z;
    ptr_a = ptr_b; // ptr_a and ptr_b now both point to x

    // Pointers vs References:
        // Pointers can be rebound to other variables, but references cannot
        ptr_a = &y;
        // You can make pointers of pointers, but references cannot
        int **ptr_c = &ptr_a;
        ptr_c;      // Accesses the address of ptr_a
        *ptr_c;     // Accesses the value of ptr_a, which is the address of y
        **ptr_c;    // Accesses the value of y
        // Pointers can be null, but references cannot
        int * ptr_null = nullptr;
}