// Static Memory: Available throughout the program
    // Global and static variables
// Local Memory: Available for the defined loop/function/scope
// Dynamic Memory: Available for a controlled period of time (via new/delete)

// Common Memory Mismanagements or Errors:
// Memory Leak: You're not using a peice of dynamic memory, but also haven't deleted it
// Orphaned Memory: You lost the address of a heap object (leading to memory leak)
// Double free: You try to free heap memory (use delete) too many times
// Non-Heap Delete: Use delete with a pointer to a non-heap object
// Wrong Delete: delete vs. delete[]
// Using a dead object: You keep the address of a dead heap object in a pointer, and accidentally use it

#include <iostream>
using namespace std;

int * multiplier(int x, int y){
    int * z = new int;
    *z = x * y;
    return z;
}

int main(){
    int *ptr = multiplier(6, 7);
    cout << *ptr << endl;
    delete ptr;

    // For new/delete with pointers, it matters which object the pointer is pointing to
    int *ptr1 = new int(1);
    delete ptr1;
    ptr1 = new int(2);
    delete ptr1;

    // Manually creating a scope to protect against dangling pointers
    {
        int *ptr_d = new int(42);
        cout << *ptr_d << endl;
        delete ptr_d;
    }

    // Dynamic Memory Allocation for Arrays
    int arrsize = 0;
    cin >> arrsize;
    int* arrPtr = new int[arrsize];
    delete[] arrPtr;
}