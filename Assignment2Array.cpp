#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <random>

using namespace std;
class Array{
  fstream inputfile;
  public:
    int n;
    int file_row;
    int file_col;

    // Getters
    int get_file_row() {
      return file_row;
    }
    int get_file_col() {
      return file_col;
    }
    // function for printing board
    void createBoard(char** arr,int x,int y) {
      for (int i=0;i<x;++i){
        for(int j=0;j<y;++j){
            cout << arr[i][j];
        }
        cout << endl;
      }
    }
    // Reading the grid from option 1 in MainMenu
    char** readBoard(string filename) {
      inputfile.open(filename);
      cout << "Opening Grid......" << endl;
      int row, col;
      if(inputfile.is_open()) {
        inputfile >> row;
        inputfile >> col;
        file_row = row;
        file_col = col;
        cout << row << " " << col << endl;
        char** arr = new char*[row];
        for(int i = 0; i < row; ++i) {
          arr[i] = new char[col];
          for(int j = 0; j < col; ++j) {
            inputfile >> arr[i][j];
          }
        }
        return arr;
      } else {
        cout << "Unable to open file" << endl;
      }

    }
    // function for making a board and 2d array for grid
    char** getBoard(int x, int y, float z){
      float density = round(x*y*z);
      cout << "Initial Bacteria Cells: " << density << endl;
      char** arr = new char*[x];
      for(int i = 0;i<x;++i){
        arr[i] = new char[i];
        for(int j = 0; j<y; ++j){
          arr[i][j] = '-';
        }
      }
      return arr;
    }
    // Method for random Distribution from option 2
    void iniDist(int x, int y, float z, char** arr){
        for(int i = 0;i<z;++i){
          random_device seed;
          mt19937 engine(seed());
          uniform_int_distribution<int> distrow(0, x-1);
          uniform_int_distribution<int> distcol(0, y-1);
          int a = distrow(engine);
          int b = distcol(engine);

          if (arr[a][b]== 'X'){
            bool eliminate = false;
            for (int i = 0; i < x; ++i){
              if(eliminate){
                break;
              }
            for (int i = 0; i < y; ++i){
              if (arr[a][b] == '-'){
                arr[a][b] = 'X';
                eliminate = true;
                break;
              }
            }
          }
        }
        arr[a][b]='X';
      }
    }
  };
