// Recursion: A function invokes (calls) itself from within its implementation
    // Breaks a complex concept into repeatable single steps

// Advantages:      Less code, cleaner
//                  Useful for sorting and searching algorithms
//                  Useful for handling tree data structures
// Disadvantages:   Slower
//                  Uses more memory

#include <iostream>
using namespace std;

void walk_iteratively(int steps);
void walk_recursively(int steps);
int factorial_iteratively(int x);
int factorial_recursively(int x);

int main(){
    walk_iteratively(5);
    walk_recursively(5);

    int a = factorial_iteratively(5); // 120
    int b = factorial_recursively(5); // 120

    cout << a << " " << b << endl;
}

//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.
void walk_iteratively(int steps){
    for(int i = 0; i < steps; i++){
        cout << "You take a step!"
        << " walk_iteratively() function call"
        << endl;
    }
}
void walk_recursively(int steps){
    if(steps > 0){
        cout << "You take a step!"
        << " walk_recursively() function call"
        << endl;
        walk_recursively(steps - 1);
    }
}

int factorial_iteratively(int x){
    int result = 1;
    for(int i = 1; i <= x; i++){
        result = result * i;
    }
    return result;
}
int factorial_recursively(int x){
    if(x > 1){
        return x * factorial_recursively(x - 1);
    } else{
        return 1;
    }
}

// g++ 21_recursion_BroCode.cpp -o 21_recursion_BroCode.exe
// ./21_recursion_BroCode.exe