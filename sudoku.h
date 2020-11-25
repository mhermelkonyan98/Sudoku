#ifndef SUDOKU_H
#define SUDOKU_H

class Sudoku {
private:
  static const int N = 9;
  int arr[N][N];
  bool findEmpty(int& row, int& col);
  bool isFree(int row, int col, int num);
  bool can_change(int row, int col, int num);

public:
  void enterDigits();
  void printSudoku();
  bool solveSudoku();
};

#endif // SUDOKU_H
