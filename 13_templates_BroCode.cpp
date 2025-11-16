// Templates: Implements a generic data type
#include<iostream>

template<typename A>
A add(A x, A y){
    return (x + y);
}

template<typename A, typename B>
auto add(A x, B y){
    return (x + y);
}

int main(){
    int a = add(2, 3);
    double b = add(2.1, 3.1);

    int c = add(2, 3.1);
    double d = add(2, 3.1);
}

// g++ 13_templates_BroCode.cpp -o 13_templates_BroCode.exe
// ./13_templates_BroCode.exe