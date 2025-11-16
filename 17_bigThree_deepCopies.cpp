// Big 3: Assignment Operators, Constructors, Destructors

  // Assignment Operators: Compilier implicitly defines a shallow-copy assignment operator
  //         Constructors: Compilier implicitly defines a shallow-copy constructor
  //          Destructors: Compilier doesn't implicitly define any destructor

  // If you have to make a custom of one (=, ctor, dtor), you likely have to make a custom of all (=, ctor, dtor)
    // REQUIRED if you need a deep copy: You need a deep copy if the object owns/manages any dynamic memory
      // CHECK if your ctor creates dynamic memory
      // CHECK if your class has pointer member variables

//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.

// Deep Copy vs Shallow Copy: Determines whether objects share the same referenced data or own independent copies.
    // Deep Copy:
        // a. Creates new copies of all member objects (recursively copies values)
        // b. Changes to the new object do NOT affect the original (and vice versa)
        // c. Slower and uses more memory
        // d. You must make your own deep copy constructor

    // Shallow Copy:
        // a. Creates a reference/pointer to the same memory object
        // b. Changes to shared members in one object will be reflected in the other
        // c. Faster and uses less memory
        // d. Each class comes with a built-in shallow-copy constructor

// 1. Deep Copy Constructor: Deep copies via initialization
    // i.   Copy regular members from rhs_copy
    // ii.  Deep copy resources from rhs_copy
// 2. Deep Copy Assignment: Deep copies via an overloaded = operator
    // i.   Check for self-assignment: Necessary incase somebody tries doing self-assignment: x = x
    // ii.  Free old resources (dynamic memory)
    // iii. Copy regular members from rhs_copy
    // iv.  Deep copy resources from rhs_copy
    // v.   Return *this
// 3. Deep Copy Destructor: Free resources

#include <iostream>
using namespace std;

const int DEFAULT_CAPACITY = 2;

class UnsortedIntSet {
    private:
    int *elts; // Dynamically Allocated Array
    int elts_size;
    int capacity;
  
    void grow(){
        int *newArr = new int[2 * capacity];
        for (int i = 0; i < elts_size; ++i) {
            newArr[i] = elts[i];
        }
        capacity *= 2;
        delete[] elts;
        elts = newArr;
    }

public:
  UnsortedIntSet(): elts(new int[DEFAULT_CAPACITY]), capacity(DEFAULT_CAPACITY), elts_size(0) {}
  
  // 1. Deep Copy Constructor
  UnsortedIntSet(const UnsortedIntSet & copy): capacity(copy.capacity), elts_size(copy.elts_size), elts(new int[capacity]){
    for(int i = 0; i < capacity; i++){
      elts[i] = copy.elts[i];
    }
  }

  // 2. Deep Copy Assignment
  UnsortedIntSet &operator=(const UnsortedIntSet& rhs_copy){
    if(this == &rhs_copy){
      return *this;
    }
    delete[] elts;
    
    capacity = rhs_copy.capacity;
    elts_size = rhs_copy.elts_size;
    elts = new int[capacity];
    for(int i = 0; i < capacity; i++){
      elts[i] = rhs_copy.elts[i];
    }
  
    return *this;
  
  }

  // 3. Deep Copy Destructor
  ~UnsortedIntSet() {
    delete[] elts;
  }

  // Copying via Pass-By-Value Functions
    // x will not create an UnsortedIntSet object
    // y WILL create an UnsortedIntSet object
    // z WILL create an UnsortedIntSet object
  void func(UnsortedIntSet &x, UnsortedIntSet y) {
    UnsortedIntSet z = x;
  }
};

// g++ 17_bigThree_deepCopies.cpp -o 17_bigThree_deepCopies.exe
// ./17_bigThree_deepCopies.exe