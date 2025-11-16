#include "map"
#include "set"
#include "algorithm"
#include "iostream"

// Maps: C++ version of dictionaries
// Sets: A map with only definitions but not their associated counterpart
    // An advantage of sets over vectors is that they cannot hold duplicates
    // Sets automatically sort via ascending order
int main(){
    std::set<std::string> names = {"Katherine", "Theo", "Bobby"};
    std::map<std::string, int> scores = {{"Katherine", 0}, {"Theo", 0}, {"Bobby", 0}}; // Holds exam scores and names
    
    // Indexing a map
    scores["Katherine"] = 98;
    std::cout << scores["Katherine"] << std::endl;

    // Iteration through a map
    auto end = scores.end();
    for(auto it = scores.begin(); it != end; it++){
        std::cout << it->first << " : " << it->second << std::endl;
    }

    // find function: map.find(key)
    // Searches a map for a particular element based on a passed-in key
    // Returns an iterator to the associated value found
    // If unsucessful, returns an end-iterator

    // insert function: map.insert(pair)
    // Inserts a new pair of values into the map
    // Returns a pair: <iterator, bool>
    // If successsful, the iterator points to the new pair of values and bool = true
    // If unsucessful, the iterator points to the existing element already there and bool = false;
}

// g++ 14_associativeContainers.cpp -o 14_associativeContainers.exe
// ./14_associativeContainers.exe