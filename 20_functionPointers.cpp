// Function Pointer: A pointer variable that can point to a function, 
//                   because a function is just a piece of memory

#include <iostream>
using namespace std;

void HelloWorld(){
    cout << "Hello World" << endl;
}
void GoodbyeWorld(){
    cout << "Goodbye World" << endl;
}
//.//.
bool is_odd(int x){
    return x % 2 != 0;
}
bool is_even(int x){
    return x % 2 == 0;
}
//.//.
int add(int x, int y){
    return x + y;
}
int subtract(int x, int y){
    return x - y;
}

//.//.
int main(){

    // Initialization syntax:
    void(*func_ptr_1)() = HelloWorld;
    func_ptr_1();                       // calls HelloWorld()

    // Function pointers can be repointed
    func_ptr_1 = GoodbyeWorld;
    func_ptr_1();                       // calls GoodbyeWorld()



    bool(*func_ptr_2)(int) = is_odd;
    func_ptr_2(3);                      // calls is_odd()
    func_ptr_2 = is_even;
    func_ptr_2(3);                      // calls is_even()



    int(*func_ptr_3)(int, int) = add;
    func_ptr_3(3, 4);                   // calls add()
    func_ptr_3 = subtract;
    func_ptr_3(3, 4);                   // calls subtract()

}

// g++ 20_functionPointers.cpp -o 20_functionPointers.exe
// ./20_functionPointers.exe