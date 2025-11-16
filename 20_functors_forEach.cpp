#include <vector>
#include <string>
#include <set>
#include <iostream>
using namespace std;

class print_greeting{
    public:
    print_greeting(){}

    void operator()(string name) const {
        cout << "Hello " << name;
    }
};

template<typename iterator, typename functor>
functor forEach(iterator begin, iterator end, functor func){
    for(; begin != end; ++begin){
        func(*begin);
    }
    return func;
}

int main(){
    vector<string> names = {"Andy", "Ava", "Jack", "Tanner", "Mark", "Griffin"};
    forEach(names.begin(), names.end(), print_greeting());
    
}

// g++ 20_functors_forEach.cpp -o 20_functors_forEach.exe
// ./20_functors_forEach.exe