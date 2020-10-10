#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class mainMenu{
  public:
    int rowInput;
    int columnInput;
    float popDensity;
    int firstinput;
    string fileName;
    int option;
    // Interface method
    void menu(){
      cout << "Hello, welcome to Game of Life!" << endl;
      cout << "Would you like to choose a file or random?"<< endl;
      cout << "1. choose a file." << endl;
      cout << "2. random file." << endl;
      cout << "3. Quit Game" << endl;
      cin >> firstinput;
      while (firstinput == 1 || firstinput == 2 || firstinput == 3){
        if (firstinput ==1){
          cout << "Please enter name of file (include .txt at the end)" << endl;
          cin >> fileName;
          option = 1;
          break;
        }
        if (firstinput == 2){
          cout << "Please enter number of rows" << endl;
          cin >> rowInput;
          cout << "Please enter number of columns" << endl;
          cin >> columnInput;
          cout << "Please enter population density(between 0 and 1)" << endl;
          cin >> popDensity;
          cout << "The number of rows: " << rowInput << endl;
          cout << "The number of columns: " << columnInput << endl;
          cout << "Population density: " << popDensity << endl;
          cout << "Creating Grid......" << endl;
          option = 2;
          break;
        }
        if (firstinput == 3){
          exit(0);
      }
    }
  }
  // Getters for variables
  int getrowInput(){
    return rowInput;
  }
  int getcolumnInput(){
    return columnInput;
  }

  int getOption() {
    return option;
  }
  float getpopDensity(){
    return popDensity;
  }
  string getFileName() {
    return fileName;
  }
};
