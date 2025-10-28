#include <fstream>
#include <string>
#include <iostream>

using namespace std;


int main(){

// Input file stream: Used to extract information from an external file into our main function
// ifstreams have more pitfalls than ofstreams:
    // Check that the ifstream reads in the correct value in the terminal/file
    // Account for the fact that ifstreams can read in "white space" and "endl" statements

ifstream my_ifstream("6_ifstream.txt");
if (!my_ifstream.is_open()){ // Check if file stream is open
    cout << "Input file stream closed." << endl;
    return 1;
}
if(!my_ifstream){ // Check if anything in the file stream has failed
    return 1;
}

string item = "";
my_ifstream >> item; // Right now, item = "apple";

double price = 0;
my_ifstream >> price; // Right now, weight = "2.71";

string color = "";
int inventory = 0;
my_ifstream >> color >> inventory;  // Multiple variables can extract information
                                    // from the input file stream

// Special input file stream implementations:
while(my_ifstream >> price){
    // Reads to the end of the file, given one variable
}
while(my_ifstream >> item >> price >> color >> inventory){
    // Reads to the end of the file, given structured data
}
string line;
while(getline(my_ifstream, line)){
    // Reads to the end of the file, given a text file
}

my_ifstream.close(); // Good practice

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
// Output file stream: Used to import information into an external file from our main function
ofstream my_ofstream("6_ofstream.txt");
if (!my_ofstream.is_open()){ // Check if file stream is open
    cout << "Output file stream closed." << endl;
    return 1;
}
if(!my_ofstream){ // Check if anything in the file stream has failed
    return 1;
}

string title = "This is an output file";
my_ofstream << title; // Right now, item = "apple";

for(int i = 0; i < 1000; i++){ 
    my_ofstream << i + 1 << endl;
}

int x = 9;
int y = 10;
my_ofstream << x + y << " is the answer" << endl; // Multiple values can be input
                                                  // into the output file stream

my_ofstream.close(); // Good practice

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
// Output string stream:
// The output of a function is stored in this variable instead of being printed to the terminal or an external file.
// Useful for unit-testing output file streams
ostringstream test_output;
string correct_output;
Matrix_print(some_image, test_output);
ASSERT_EQUAL(test_output.str(), correct_output);

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
// Input string stream:
// This variable can mimic the functions of an input file stream without involving external files
// Useful for unit-testing input file streams
istringstream test_input;
string correct_input;
ASSERT_EQUAL(test_input.str(), correct_input);
}

// g++ 6_input-outputStream.cpp --o 6_input-outputStream.exe
// ./6_input-outputStream.exe