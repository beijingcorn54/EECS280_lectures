#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>

using namespace std;

// argc and argv: parameters passed into the main function

// argc: Number of argumentsd passed into the main functions through terminal commands
// *argv[] (A pointer of pointers of vectors): This essentially holds the names of all the arguments passed into the main function

// Example Call:
// ./6_argc_arcv.exe 6_ifstream.txt 6
    // 6_ifstream.txt- The name of the input file to be read into the main function
    // 6 - number of times the message will be read


void print(istream &fin){
  string fruit;
  bool price = 0;
  string color;
  int quantity = 0;

  while(fin >> fruit >> price >> color >> quantity){
    cout << "Fruit: " << fruit << "; Price: " << price << "; Color: " << color << "; Quantity: " << quantity << " ||" << endl;
  }
}

int main(int argc, char *argv[]) {

  if(argc != 3){
    cout << "Not enough arguments: ./6_argc_arcv.exe yourInputFile.txt integer" << endl;
    return 1;
  }

  string input = argv[1];
  string str_output = argv[2];

  int num_output = stoi(str_output);


  ifstream fin(input);
  if(!fin.is_open()){
    cout << "Input filestream failed to open" << endl;
    return 1;
  }

  for (int i = 0; i < num_output; i++){
    print(fin);
    cout << endl;
  }
}
