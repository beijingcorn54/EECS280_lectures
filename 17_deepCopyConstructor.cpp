#include <iostream>
using namespace std;

const int DEFAULT_CAPACITY = 2;

class UnsortedIntSet {
public:
  
  UnsortedIntSet(): elts(new int[DEFAULT_CAPACITY]), capacity(DEFAULT_CAPACITY), elts_size(0) {}
  
  // Deep Copy Constructor: Deep copies via initialization
  UnsortedIntSet(const UnsortedIntSet & copy): capacity(copy.capacity), elts_size(copy.elts_size), elts(new int[capacity]){
    for(int i = 0; i < capacity; i++){
      elts[i] = copy.elts[i];
    }
  }
  
  ~UnsortedIntSet() {
    delete[] elts;
  }
//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.
  
  // EFFECTS: adds v to the set
  void insert(int v) {
    if (contains(v)) {
      return;
    }
    
    // Increase capacity if needed
    if (elts_size == capacity) {
      grow();
    }
    
    elts[elts_size] = v;
    ++elts_size;

  }
   
  // EFFECTS: removes v from the set
  void remove(int v) {
    if (!contains(v)) {
      return;
    }
    elts[indexOf(v)] = elts[elts_size - 1];
    --elts_size;
  };
  
  // EFFECTS: returns whether v is in the set
  bool contains(int v) const{
    return indexOf(v) != -1;
  }
  
  // EFFECTS: returns the number of elements
  int size() const{
    return elts_size;
  }
  
  // Implemented for you. You're welcome :)
  void print(ostream &os) const {
    os << "{ ";
    if (elts_size > 0){
      os << elts[0];
    }
    for(int i = 1; i < elts_size; ++i){
      os << ", " << elts[i];
    }
    os << " }";
  }
    
private:
  // Points to a dynamically allocated array on the heap
  int *elts;
  
  // Represents the current number of valid elements in the set
  int elts_size;
  
  // Represents the current capacity of the underlying array
  int capacity;
  
  // Allocates a new dynamic array with twice the capacity.
  // Then, copies over the elements from the old array.
  // Finally, frees the memory for the old array and
  // points the elts pointer to the new array.
  void grow() {
    int *newArr = new int[2 * capacity];
    for (int i = 0; i < elts_size; ++i) {
      newArr[i] = elts[i];
    }
    capacity *= 2;
    delete[] elts;
    elts = newArr;
  }

  
  // EFFECTS: Returns the index of the v in the elts
  //          array. If not present, returns -1.
  int indexOf(int v) const{
    for(int i = 0; i < elts_size; ++i){
      if(elts[i] == v){
        return i;
      }
    }
    return -1;
  }
};


ostream &operator<<(ostream &os, const UnsortedIntSet &s) {
  s.print(os);
  return os;
}


int main() {
  UnsortedIntSet s1;
  
  s1.insert(2);
  s1.insert(3);
  
  UnsortedIntSet s2 = s1; // use copy ctor
  // The line above is equivalent to UnsortedIntSet s2(s1);
  
  s2.remove(3);
  s2.insert(5);

  cout << s1 << endl; // prints { 2, 3 }
  cout << s2 << endl; // prints { 2, 5 }
}