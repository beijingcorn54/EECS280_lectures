// Tail Recursion:  The recursion call is the LAST STEP of the function
//                  which reduces memory usage

// 1. Base case will return the answer
// 2. Computation; Use an accumulator parameter to collect the answer
// 3. Recursion

#include <iostream>
using namespace std;

int factorial_regular(int x);
int factorial_tailRecursion(int x, int result_so_far);
int factorial_tailRecursion_singleParameter(int x);

int main(){

    int a = factorial_regular(5);                       // 120
    int b = factorial_tailRecursion(5, 1);              // 120
    int c = factorial_tailRecursion_singleParameter(5); // 120

    cout << a << " " << b << " " << c << endl;

}

int factorial_regular(int x){
    if(x > 1){
        return x * factorial_regular(x - 1);
    } else{
        return 1;
    }
}
int factorial_tailRecursion(int x, int result_so_far){
    if(x == 0){
        return result_so_far;
    } else{
        return factorial_tailRecursion(x - 1, x * result_so_far);
    }
}

// This doesn't significantly change how memory is stored,
// it just cleans up the factorial interface
int factorial_tailRecursion_singleParameter(int x){
    return factorial_tailRecursion(x, 1);
}

// g++ 21_tailRecursion_factorial.cpp -o 21_tailRecursion_factorial.exe
// ./21_tailRecursion_factorial.exe