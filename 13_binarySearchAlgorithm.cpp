// Sorted Data Structures, Templates
#include <utility>
#include<iostream>
#include <vector>

using namespace std;

const int binarySearch(int target_value, int start_index, int end_index, const vector<int> &v);

int main(){
    vector<int> v = {0, 10, 20, 30, 40, 50};
    int index_of_2 = binarySearch(20, 0, v.size(), v);
    int index_not_found = binarySearch(112342, 0, v.size(), v);
}

// Binary search function that returns the index of a target value in a vector
const int binarySearch(int target_value, int start_index, int end_index, const vector<int> &v){
    while (start_index != end_index) {
        int middle = start_index + (end_index - start_index) / 2;
        if (target_value == v.at(middle)) {
            return middle;
        }
        else if (target_value < v.at(middle)) {
            end_index = middle;
        }
        else {
            start_index = middle;
        }
    }
    return -1;
}