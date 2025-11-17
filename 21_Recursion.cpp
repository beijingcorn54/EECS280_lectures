// Helpful strategies:
    // Explicit Formula for Arithmetic Series:  a_n = a_1 + d*(n - 1)
    // Explicit Formula for Geometric Series:   a_n = a_1 * r ^ (n - 1)
    // Explicit Formula for Harmonic Series:    a_n = (a_1 + d*(n - 1)) ^ -1

// Recursion Strategy:
    // 1. Find base case
    // 2. Find recurrance
    // 3. Clean up loose ends (if necessary)

// Tail Recursion:  The recursion call is the LAST STEP of the function
//                  which reduces memory usage

//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.
#include <iostream>
using namespace std;
// Reversing an Array

    // EFFECTS: Reverses the array starting at 'left'
    //          and ending at (and including) 'right'.
    void reverse(int *left, int *right) {
    // (1) detect base case and just return (no work to do)
    if(left < right){
        // (3) swap first and last elements
        int storage_left = *left;
        *left = *right;
        *right = storage_left;

        // (2) reverse middle of array using recursion
        // Recursion at the end due to tail recursion
        reverse(left + 1, right - 1);
    }
}

void printArray(int *array, int size) {
  for (int i = 0; i < size; ++i) {
    cout << array[i] << " ";
  }
  cout << endl;
}

int main() {
  const int SIZE = 4;
  int array[4] = { 1, 2, 3, 4 };
  cout << "Original: ";
  printArray(array, SIZE);

  reverse(array, array + SIZE - 1);
  cout << "Reversed: ";
  printArray(array, SIZE);
}

// g++ 21_recursion.cpp -o 21_recursion.exe
// ./21_recursion.exe