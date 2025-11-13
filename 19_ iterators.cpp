// You can make abstract iterators as a nested class in the public section

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

public:
class Iterator{
    // Friend class declaration: linkedList may use private members of Iterator
    friend class linkedList;
private:
    Node *nodeptr;
    linkedList *listptr;
    Iterator(Node *nodeptr): nodeptr(nodeptr){}

public:
    Iterator(): nodeptr(nullptr){}

    T &operator*() const{
        assert(nodeptr);
        return nodeptr->datum;
    }
    // prefix ++ operator (++it)
    Iterator &operator++() {
        assert(nodeptr);
        nodeptr = nodeptr->next;
        return *this;
    }
    // postfix ++ operator (it++)
    Iterator &operator++(T /*required syntax for postfix*/){
        Iterator copy = *this;
        operator++();
        return copy;
    }
    // postfix/prefix -- operator
    Iterator &operator--(){
        if(nodeptr){
            nodeptr = nodeptr->prev;
        } else{
            nodeptr = listptr->last;
        }
        return *this;
    }
    bool operator==(Iterator rhs) const{
        return nodeptr == rhs.nodeptr;
    }
    bool operator!=(Iterator rhs) const{
        return nodeptr != rhs.nodeptr;
    }
};
    Iterator begin() const{
        return Iterator(first);
    }
    Iterator end() const{
        return Iterator(nullptr);
    }
//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.
//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.
//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.

        void copy_all(const linkedList &other){
            for(T *ptr = other.first; ptr; ptr = ptr-next){
                push_back(ptr->datum);
            }
        }

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
            if(!first){
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
            if(!first){
                last = nullptr;
            } else{
                first->prev = nullptr;
            }
            delete originalFirst;
            _size--;
        }

        void push_back(const T &new_datum){
            Node *newNode = new Node{new_datum, nullptr, last};
            if(!last){ 
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
            if(!last){
                first = nullptr;
            } else {
                last->next = nullptr;
            }
            delete originalLast;
            _size--;
        }
        void print(ostream &os) const {
            for(Node *ptr = first; ptr; ptr = ptr->next) {
                os << ptr->datum << " " << endl;
            }
        }
};
//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.
//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.
//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.//.
template<typename it>
it max_element(it begin, it end){
    it max = begin;
    for(it x = begin; x != end, x++){
        if(*max < *x){
            max = x;
        }
    }
    return max;
}

template <typename it>
int length(it begin, it end) {
  int count = 0;
  while(begin != end) {
    ++count;
    ++begin;
  }
  return count;
}

int main(){
    linkedList<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);

    linkedList<int>::Iterator end = l.end();
    for(linkedList<int>::Iterator it = l.begin(); it != end; it++){
        cout << *it << endl;
    }

    vector<int> v = {1,2,3,4,5};

    auto x = max_element(v.begin(), v.end());

}