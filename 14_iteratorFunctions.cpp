#include "vector"
#include "iostream"
#include "algorithm"

int main(){
    std::vector<int> v = {0,1,2,3,4,5,6,7,8,9};
    auto it_v = v.begin();

    // Iterators with "algorithm" library
    auto it_vMAX = std::max_element(v.begin(), v.end());
    int max_element = *it_vMAX;

    std::sort(v.begin(), v.end());

    
}

// Making iterator functions
template <typename my_iterator_type>
bool my_is_empty(my_iterator_type begin, my_iterator_type end){
    if(begin == end){
        return true;
    } else{
        return false;
    }
}

// g++ 14_iteratorFunctions.cpp -o 14_iteratorFunctions.exe
// ./14_iteratorFunctions.exe