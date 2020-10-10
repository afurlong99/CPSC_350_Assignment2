// Packages
#include <iostream>
#include <string>
#include <fstream>
#include "Assignment2MainMenu.cpp"
#include "Assignment2Array.cpp"
#include "Assignment2GameRun.cpp"
using namespace std;

int main(){

    int secondInput;

    mainMenu a;
    a.menu();

    Array b;
    int r = a.getrowInput();
    int c = a.getcolumnInput();
    float p = a.getpopDensity();
    char**arr;
    if(a.getOption() == 1) {
      arr = b.readBoard(a.getFileName());
      r = b.get_file_row();
      c = b.get_file_col();
    }
    else {
      arr = b.getBoard(r,c,p);
      float density = round(r*c*p);
      b.iniDist(r,c,density,arr);
    }
    GameRun d = GameRun(arr, r, c);
    cout << "Run:" << endl;
    d.runGame('m', 's'); // ('mode: one of 'm', 'c', 'd'', 'next')
    return 0;
}
