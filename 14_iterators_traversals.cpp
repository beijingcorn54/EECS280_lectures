#include "vector"
#include "iostream"

int main(){
    std::vector<int> v = {0,1,2,3,4,5,6,7,8,9};
    std::vector<int>::iterator it_v = v.begin();

     // Traversal by iterator
     std::vector<int>::iterator end = v.end();
     for(std::vector<int>::iterator it = v.begin(); it != end; ++it){
        std::cout << *it << std::endl;
     }

   // Range-based For loop: special syntax for iterating over a sequence
     // It does this by condensing the regular traversal sytax
     for(int i : v){
      std::cout << i << std::endl;
     }
     // Changing vector values via range-based for-loop:
     // Since an iterator is similar to a pointer, it must
     // be dereferenced to access its values
     for(int &i : v){
      i = 42; // sets all elements to 42
     }
}

// g++ 14_iterators_traversals.cpp -o 14_iterators_traversals.exe
// ./14_iterators_traversals.exe