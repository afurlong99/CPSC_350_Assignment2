#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <random>
using std::cout;
using std::endl;
class GameRun {
private:
  char** arr;
  int rows;
  int cols;
public:
  // GameRun constructor
  GameRun(char** arr_, int i, int j){
    arr = arr_;
    rows = i;
    cols = j;
  }
  // Print Array
  void print_array() {
    for (int i=0;i<rows;++i){
      for(int j=0;j<cols;++j){
          cout << arr[i][j];
      }
      cout << endl;
    }
  }

  // Check to see if the grid has stabilized
  bool stabalized(char** to_check) {
    for (int i=0;i<rows;++i){
      for(int j=0;j<cols;++j){
          if(arr[i][j] != to_check[i][j]) {
            return false;
          }
      }
    }
    return true;
  }
  // Check to see the cells in the grid are dead
  bool dead() {
    for (int i=0;i<rows;++i){
      for(int j=0;j<cols;++j){
          if(arr[i][j] == 'X') {
            return false;
          }
      }
    }
    return true;
  }
  // parameters for doughnut mode
  int wrapped(int val, int max) {
    if (val < 0) {
      return max-1;
    } else if (val == max){
      return 0;
    } else return val;
  }
  // parameters for mirror mode
  int mirror(int val, int max) {
    if (val < 0) return 0;
    else if(val >= max) return max-1;
      else return val;
  }
  //  Return row values for each game mode
  int wrap_row(int val, char w) {
    if(w == 'c') return val;
    else if(w == 'd') return wrapped(val, rows);
    else if(w == 'm') return mirror(val, rows);
      else return -1;
  }
  // Return column values for each game mode
  int wrap_col(int val, char w) {
    if(w == 'c') return val;
    else if(w == 'd') return wrapped(val, cols);
    else if (w == 'm') return mirror(val, cols);
      else return -1;
  }
  // Game Logic comparing neighbour positions
  char modify_cell(int x, int y, char w) {
    int live = 0;
    if (wrap_row(x - 1, w) >= 0 && wrap_col(y - 1, w) >=0 && arr[wrap_row(x - 1, w)][wrap_col(y - 1, w)] == 'X') live++;
    if (wrap_row(x - 1, w) >= 0 && arr[wrap_row(x - 1, w)][y] == 'X') live++;
    if (wrap_row(x - 1, w) >= 0 && wrap_col(y + 1, w) < cols && arr[wrap_row(x - 1, w)][wrap_col(y + 1, w)] == 'X') live++;
    if (wrap_col(y - 1, w) >= 0 && arr[x][(wrap_col(y - 1, w))] == 'X') live++;
    if (wrap_col(y + 1, w) < cols && arr[x][wrap_col(y + 1, w)] == 'X') live++;
    if (wrap_row(x + 1, w) < rows && wrap_col(y - 1, w) >=0 && arr[wrap_row(x + 1, w)][wrap_col(y - 1, w)] == 'X') live++;
    if (wrap_row(x + 1, w) < rows && arr[wrap_row(x + 1, w)][y] == 'X') live++;
    if (wrap_row(x + 1, w) < rows && wrap_col(y + 1, w) < cols && arr[wrap_row(x + 1, w)][wrap_col(y + 1, w)] == 'X') live++;
    // Game logic changing positions to 'X' or keeping "-"
    if(live < 2) return '-';
    else if(live == 2) return arr[x][y];
    else if(live == 3) return 'X';
    else if(live > 3) return '-';
    else return 1;
  }
 // Methods to invoke char** next
  void copy_to_arr(char** next) {
    for (int i=0;i<rows;++i){
      for(int j=0;j<cols;++j){
          arr[i][j] = next[i][j];
      }
    }
  }

  void copy_from_arr(char** next) {
    for (int i=0;i<rows;++i){
      for(int j=0;j<cols;++j){
          next[i][j] = arr[i][j];
      }
    }
  }
 // Method used from other functions in the class to run the game
  void runGame(char mode, char nextStep) {
    int gen = 0;
    char** next = new char* [rows];
    for(int i = 0; i < rows; ++i) {
      next[i] = new char[cols];
    }
    copy_from_arr(next);
    while(true) {
      cout << "generation " << ++gen << endl;
      print_array();
      for (int i=0;i<rows;++i){
        for(int j=0;j<cols;++j){
            next[i][j] = modify_cell(i, j, mode);
        }
      }
      if(stabalized(next)) break;
      copy_to_arr(next);
      if(dead()) break;
    }
    delete[] next;
  }
};
