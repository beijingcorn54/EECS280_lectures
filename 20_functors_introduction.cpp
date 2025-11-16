// Functor: A class-type object that mimics a function via function overloads
    // Iterator: An class-type object that mimics a pointer
    // Functor: An class-type object that mimics a function
#include <vector>
using namespace std;

// Functor
class divisible_by{
    private:
    int num;

    public:
    divisible_by(int num): num(num){}

    bool operator()(int x) const {  // MAKE SURE TO INCLUDE THIS CONST,
        return x % num == 0;        // BUT LOOK OUT FOR EXCEPTIONS
    }
};

// Higher order function
vector<int> classify_divisible_by(const vector<int> v, divisible_by func){
    vector<int> return_v;
    for(size_t i = 0; i < v.size(); i++){
        if(func(v.at(i))){
            return_v.push_back(v.at(i));
        }
    }
    return return_v;
}

int main(){
    divisible_by is_even(2);
    divisible_by is_div_by_10(10);

    bool a = is_even(3);
    bool b = is_even(4);

    bool c = is_div_by_10(4);
    bool d = is_div_by_10(40);

    vector<int> v = {-3, -2, -1, 0, 1, 2, 3};

    vector<int> even_ints = classify_divisible_by(v, is_even);
    vector<int> ints_of_three = classify_divisible_by(v, divisible_by(3));

}

// g++ 20_functors_introduction.cpp -o 20_functors_introduction.exe
// ./20_functors_introduction.exe