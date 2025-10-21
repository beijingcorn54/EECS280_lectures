// NEW DATA TYPE: Pair - A coordinate pair
#include <utility>
#include<iostream>
using namespace std;


int main(){


    pair<double, double> xy_coords(232.2, -57.12);
    pair<int, string> student(1, "Alice");


    cout << "ID: " << student.first << endl;
    cout << "Name: " << student.second << endl;


    // You can also RETURN a pair as such: {1, 2}
    // pair<int,int> myFunction(){
    // return {1, 2};
    //}

    // Casting: Explicity changing the data type of a variable
    string number_string = "123";
    int number_int = stoi(number_string);
    double number_double = stod(number_string);
    bool bool_int = static_cast<bool>(number_int);
    bool bool_double = static_cast<bool>(number_double);
}