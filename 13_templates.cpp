// Templates:
// Implements a generic class with a flexible element type
#include <utility>
#include<iostream>
#include <vector>

template<typename T>

class unsortedVector{
    private:

    vector<T> v;
    static int array_size = 10;
    T arr[array_size];

    public:

    void insert(T arr);
    void remove(T arr);
};

template<typename T> // Needed before every function implementation outside the class
void unsortedVector<T>::insert(T arr){
    // Implementation for an array
}
template<typename T>
void unsortedVector<T>::remove(T arr){
    // Implementation for an array
}
