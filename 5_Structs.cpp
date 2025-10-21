#include <utility>
#include<iostream>
using namespace std;


// Abstract Data Type (Classes, objects, etc): Make-your-own data type that holds custom functions and parameters

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
    (*ptr_person).age;  // Accesses Richard's age: 18
    ptr_person->age;    // Does same thing

}