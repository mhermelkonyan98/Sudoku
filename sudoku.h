#ifndef SUDOKU_H
#define SUDOKU_H

const int N = 9;

class Sudoku {
private:
  int arr[N][N];
public:
  void enterDigits();
  void printSudoku();
  bool solveSudoku();
  bool findEmpty(int& row, int& col);
  bool isFree(int row, int col, int num);
  bool can_change(int row, int col, int num);
};

#endif
