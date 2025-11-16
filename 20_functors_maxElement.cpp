#include <vector>
#include <string>
#include <set>
using namespace std;

template<typename T>
class num_less{
    public:
    num_less(){}

    bool operator()(T a, T b) const {
        return a < b;
    }
};

class compare_alpha{
    private:
    set<string> s;

    public:
    compare_alpha(){}

    bool operator()(string a, string b){ // Note, does NOT have a "const" qualifier
        s.insert(a);
        bool succesful_insert = s.insert(b).second;
        if(succesful_insert && (*s.begin() == b)){
            return true;
        }
        return false;
    }
};

template<typename iterator, typename functor>
iterator find_max(iterator begin, iterator end, functor less){
    iterator max = begin;
    for(; begin != end; ++begin){
        if(less(*max, *begin)){
            max = begin;
        }
    }
    return max;
}

int main(){
    vector<string> v_s = {"apple", "andy", "corona", "zebra", "shower", "avalanch", "pasta", "apple"};
    vector<double> v_values = {1, -23, 595.9, 29.1};
    
    compare_alpha f();
    string max_string = *find_max(v_s.begin(), v_s.end(), f);
    
    double max_value = *find_max(v_values.begin(), v_values.end(), num_less<double>());
}

// g++ 20_functors_maxElement.cpp -o 20_functors_maxElement.exe
// ./20_functors_maxElement.exe