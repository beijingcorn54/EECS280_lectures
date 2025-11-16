#include "vector"
#include "iostream"

// "auto" Keyword: The compiler automatically figures out what type of variable it is
int main(){
    auto v = {0,1,2,3,4,5,6,7,8,9};

    auto it_v = v.begin();
    auto my_string = "Hello world";

    std::cout << *(it_v + 1) << std::endl;
    std::cout << my_string << std::endl;

    auto end = v.end();
    for(auto i = v.begin(); i < end; i++){
        std::cout << *i << std::endl;
    }
}

// g++ 14_autoKeyWord.cpp -o 14_autoKeyWord.exe
// ./14_autoKeyWord.exe