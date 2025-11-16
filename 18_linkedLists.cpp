// Sequential Containers: Order matters, can hold duplicates (eg. vector, array)
// Associative Containers: Order doesn't matter, but cannot hold duplicates (eg. set, map)

// Contiguous Memory: Memory is stored next to eachother in computer memory
    // Efficient indexing: O(1)
    // Ineficient insertion operations: O(n)
    // Iteration: ptr++

// Linked Structures: Memory is in linked nodes, not in any particular part of computer memory
    // Ineficient indexing: O(n)
    // Eficient insertion operatioins: O(1)
    // Iteration: ptr = ptr->next

    // Each node contains a datum and a pointer to the next datum in the list


// Arrays vs Linked Lists

// Array-Based Ordered Container: Superior approach for most applications
    // 1.   Efficient O(1) indexing
    // 2.   Inefficient O(n) insert/erase in middle, since elements must be shifted
    //      to preserve ordering
    // 3.   Efficient O(1) push/pop from either end (assuming a circular buffer if 
    //      you need to work from both ends)
    
    // Better performance via memory caching and low memory overhead

// Linked List: Generally slower with larger memory overhead
    // 1.   Inefficient O(n) indexing
    // 2.   Efficient O(1) insert/erase anywhere, assuming you already have a 
    //      pointer to the insert/erase location
    // 3.   Efficient O(1) push/pop from either end

    // Useful in particular applications where the advantages of a linked 
    // list align precisely with what is needed (and where slow indexing is acceptable)
#include <iostream>
#include <cassert>
using namespace std;

template<typename T>
class linkedList {
    private:
        struct Node {
            T datum;
            Node *next;
            Node *prev;
        };

        Node *first;
        Node *last;
        size_t _size;

        void copy_all(const linkedList &other){
            for(T *ptr = other.first; ptr; ptr = ptr-next){
                push_back(ptr->datum);
            }
        }

    public:
        linkedList(): first(nullptr), last(nullptr), _size(0) {}
        linkedList(const linkedList &other):first(nullptr), last(nullptr), _size(0){
            copy_all(other);
        }

        linkedList & operator=(const linkedList &rhs){
            if(this != &rhs){
                clear();
                copy_all(rhs);
            }
            return *this;
        }

        ~linkedList(){
            clear();
        }

        void clear(){
            while(!is_empty()){
                pop_front();
            }
        }
        bool is_empty() const {
            return !first;
        }

        T &get_front() {
            assert(!is_empty());
            return first->datum;
        }
        T &get_back() {
            assert(!is_empty());
            return last->datum;
        }
        size_t get_size() const {
            return _size;
        }

    
        void push_front(const T &new_datum){
            Node *newNode = new Node{new_datum, first, nullptr};
            if(!first){ // Empty list
                last = newNode;
            } else{
                first->prev = newNode;
            }
            first = newNode;
            _size++;
        }

        void pop_front(){
            assert(!is_empty());

            Node *originalFirst = first;
            first = first->next;
            if(!first){ // list became empty
                last = nullptr;
            } else{
                first->prev = nullptr;
            }
            delete originalFirst;
            _size--;
        }

        void push_back(const T &new_datum){
            Node *newNode = new Node{new_datum, nullptr, last};
            if(!last){ // list was empty
                first = newNode;
            } else{
                last->next = newNode;
            }
            last = newNode;
            _size++;
        }

        void pop_back() {
            assert(!is_empty());
            Node *originalLast = last;
            last = last->prev;
            if(!last){ // list became empty
                first = nullptr;
            } else {
                last->next = nullptr;
            }
            delete originalLast;
            _size--;
        }

    // Traversal through a linked list: 
    // (ptr != nullptr) condition can be simplified to (ptr) 
    // because a (nullptr) will contextually simplify to (false)
        void print(ostream &os) const {
            for(Node *ptr = first; ptr; ptr = ptr->next) {
                os << ptr->datum << " " << endl;
            }
        }
};


// g++ 18_linkedLists.cpp -o 18_linkedLists.exe
// ./18_linkedLists.exe