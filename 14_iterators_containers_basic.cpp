#include "vector"
#include "iostream"
#include "list"
#include "algorithm"
// Contiguous Allocation: Elements are stored right next to each other in a container
// Cannot easily add elements to the front of the container
// Can index easily
    // Vectors: std::vector<int> v
        // Uses separate variables to track capacity vs size
        // Uses an internal pointer to be dynamically sized
    // Arrays: std::array<int, 3> a = {1,2,3}

// Linked structure: Elements are stored in nodes that point to each other
// Can dynamically add elements to the front of a list
// Cannot index easily
    // Lists
    // Forward lists

// Associative Containers: Maps a unique key to a unique value (ex. f(x) = y)
    // A map is the C++ version of a dictionary
    // A set is a map with only definitions but not their associated counterpart

// Iterator: Indicates the index of a particular element in a container
    // Similar to a pointer. It can point to things and be dereferenced, but it's not exactly a pointer
    // Can be used for all container types (with exceptions)
    // std::vector<int>::interator it_v = v.begin()
int main(){
    std::vector<int> v = {0,1,2,3,4,5,6,7,8,9};

    std::vector<int>::iterator it_v = v.begin();

    // Iterating the iterator
    it_v++;
    ++it_v;
    --it_v;

    // Dereferencing the iterator
    it_v = v.begin() + 4;

    *it_v = 10;
    std::cout << *it_v << std::endl; // Prints 10

    // Equality checks
     std::vector<int>::iterator it_v_at_6 = v.begin() + 6;
     bool a = (it_v == it_v_at_6);
     bool b = (*it_v != 3);

     // Iterator operations only valid for contiguous containers
     it_v = v.begin() + 3; // Moving the iterator by a specific amount
     it_v += 4;
     bool c = (it_v < v.end()); // Comparison
     bool d = (it_v < v.end() - 1);

     // Iterator INVALIDATION:
     // Certain operations on a container can cause an iterator
     // to become invalid
     std::list<int> l;
     l.push_back(0);
     l.push_back(1);
     l.push_back(2);

     std::list<int>::iterator it_l1 = l.begin();
     std::list<int>::iterator it_l2 = l.begin();
     l.erase(it_l1);

     std::cout << *it_l1 << std::endl; // INVALID
     std::cout << *(++it_l2) << std::endl; // INVALID
}