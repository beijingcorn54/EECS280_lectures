// Higher Order Function: A function that can take in other funtions as parameters
// Predicate: A simple boolean function that is usually passed into a higher order function

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool is_even(int x){
    return x % 2 == 0;
}

bool is_negative(int x){
    return x < 0;
}

bool is_divisible_by_three(int x){
    return x % 3 == 0;
}

unordered_map<int, bool> classify_integers(const vector<int> v, bool(*fptr)(int)){
    unordered_map<int, bool> return_m;
    for(size_t i = 0; i < v.size(); i++){
        return_m.insert({v.at(i), fptr(v.at(i))});
    }
    return return_m;
}

int main(){
    vector<int> v = {-3, -2, -1, 0, 1, 2, 3};

    bool(*func_ptr)(int) = is_negative;
    unordered_map<int, bool> negative_values = classify_integers(v, func_ptr);

    bool(*func_ptr)(int) = is_even;
    unordered_map<int, bool> even_values = classify_integers(v, func_ptr);

    bool(*func_ptr)(int) = is_divisible_by_three;
    unordered_map<int, bool> divis_by_three = classify_integers(v, func_ptr);
}

// g++ 20_higherOrderFunctions_functionPointers.cpp -o 20_higherOrderFunctions_functionPointers.exe
// ./20_higherOrderFunctions_functionPointers.exe