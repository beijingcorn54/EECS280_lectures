#include <utility>
#include<iostream>
using namespace std;


// Abstract Data Type (Classes, objects, etc): Make-your-own data type that holds custom functions and parameters
// NOTE ON POINTERS: For any pointer to an ADT, use -> to access any member of that ADT

// Structs
struct Person{
    int age;
    string name;
    double height, weight, bench_pr;
    vector<int> favNums;
};

int main(){
    Person Kate;
    Kate = {19, "Kate", 100};
    Kate.height = 99.78;
    Kate.favNums = {1,2,3,4,5,6,7};
    Kate.favNums[0] = 0;
    const Person Richard = {18, "Richard", 180};

    // Pointers with structs
    const Person * ptr_person = &Richard;
    cout << (*ptr_person).age << endl;  // Accesses Richard's age: 18
    cout << ptr_person->age << endl;    // Does same thing, but this respects the struct interface

}

// g++ 5_Structs.cpp -o 5_Structs.exe
// ./5_Structs.exe