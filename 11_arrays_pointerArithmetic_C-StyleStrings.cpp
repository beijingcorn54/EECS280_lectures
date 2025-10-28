// Arrays, Pointer Arithmetic, C-Style Strings

#include <utility>
#include<iostream>
using namespace std;


int main(){
    
    int my_array[6] = {0, 10, 20, 30, 40, 50}; // Array declaration
    std::array<int, 6> your_array = {0, 1, 2, 3, 4, 5}; // Alternate Array declaration
    // Arrays may not be resized
    // Arrays store memory junk upon initialization

    my_array[3]; // returns "3"
    my_array[3] = -23;

    // int your_array[6] = my_array; // ERROR: you're not allowed to assign arrays to eachother

    int *arrayPtr = my_array; // Arrays decay into pointers of the first element
    cout << *arrayPtr << endl; // Prints "0"
    
    // Array Addition: Computes an array offset
    int *arrayPtr2 = my_array + 2;
    cout << *arrayPtr2 << endl; // Prints "20"

    *arrayPtr = *(my_array + 3); 
    cout << *arrayPtr << endl; // Prints "-23"

    // Array Subtraction: Computes the number of indexes between the two arrays
    cout << arrayPtr - *(arrayPtr + 3) << endl; // Prints "-3"

    // Array Indexing
    cout << my_array[4] << endl; // Prints 40
    cout << *(my_array + 2) << endl; // Prints 20

    // Traversals by pointer for arrays
    int size = 100;
    int traversal_array[size]; // Array declaration
    int *end = my_array + size;
    for(int *ptr = my_array; ptr < end; ptr++){
        cout << *ptr << endl;
    }
    for(int *ptr = my_array; ptr < my_array + size; ptr++){ // Also acceptable syntax
        cout << *ptr << endl;
    }

    // Strings stored as arrays
        // The end of every string-stored-as-array (C-style string) ends with a null-character
        // Use traversal by pointer to iterate through characters in a C-style string
        //  == CANNOT be used to compare C-style strings

    char my_string[6] = "Hello";
    char your_string[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
    char *strPtr = my_string;
    while(*strPtr != '\0'){
        cout << *strPtr;
        strPtr++;
    }
}