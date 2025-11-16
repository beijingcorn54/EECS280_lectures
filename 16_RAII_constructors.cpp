// RAII: Resource Aquisition Is Initialization
// A method for handling the construction/destruction of dynamic memory
using namespace std;

class array_class{
    private:
    int *arr;
    int capacity;

    public:
    // Constructor initializes an object to dynamic memory
    array_class(): arr(new int[1]), capacity(1) {
        arr[0] = 0;
    }
    array_class(int size): arr(new int[size]), capacity(size) {
        for(int i = 0; i < size; i++){
            arr[i] = 0;
        }
    }

    // Destructor deletes the object from dynamic memory
        // NOTE: The destructor does not destroy the object, it just cleans up dynamic memory
    ~array_class(){
        delete[] arr;
    }

    void grow() { // Doubles the size of the array without changing the elements or their order
        int *temp_arr = new int[capacity * 2];
        for(int i = 0; i < capacity; i++){
            temp_arr[i] = arr[i];
        }
        capacity *= 2;
        arr = temp_arr;
        delete[] temp_arr;
    }

};


// g++ 16_RAII_constructors.cpp -o 16_RAII_constructors.exe
// ./16_RAII_constructors.exe