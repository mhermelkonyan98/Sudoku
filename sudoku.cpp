#include "sudoku.h"
#include <iostream>

//Մատրիցի մուտք:
void Sudoku::enterDigits() {
    std::cout << "Enter your favorite unsolved Sudoku (9x9 Matrix). If cell is empty, enter ZERO (0)!" << std::endl;
    std::cout << std::endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> arr[i][j];
        }
    }
}

//Մատրիցի ելք:
void Sudoku::printSudoku() {
    std::cout << "It's too easy :) Below is the solution of your Sudoku. Good luck!" << std::endl;
    std::cout << std::endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

//Սուդոկու խաղի լուծումը բուլյան ֆունկցիայով:
bool Sudoku::solveSudoku() {
    int row, col;
    if (findEmpty(row, col)) {
        for (int num = 1; num <= N; num++) {
            if (can_change(row, col, num)) {
                arr[row][col] = num;
                if (solveSudoku()) {
                    return true;
                }
                arr[row][col] = 0;
            }
        }
        return false;
    }
    else {
        return true;
    }
}

//Ստուգենք, արդյոք դատարկ է տվյալ բջիջը:
bool Sudoku::findEmpty(int& row, int& col) {
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (arr[row][col] == 0) {
                return true;
            }
        }
    }
    return false;
}

//Ստուգենք, արդյոք կարող ենք փոփոխել բջջի պարունակությունը:
bool Sudoku::isFree(int row, int col, int num) {
    for (int i = 0; i < N; i++) {
        if (arr[row][i] == num) {
            return false;
        }
    }

    for (int i = 0; i < N; i++) {
        if (arr[i][col] == num) {
            return false;
        }
    }

    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (arr[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }
    return true;
}

bool Sudoku::can_change(int row, int col, int num) {
    if (isFree(row, col, num)) {
        return true;
    }
    return false;
}

