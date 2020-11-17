#include "sudoku.h"
#include <iostream>

int main() {
    Sudoku player;
    player.enterDigits();
    std::cout << std::endl;
    if (player.solveSudoku()) {
        player.printSudoku();
    }
    else {
        std::cout << "WARNING! No solution exists. Try again with correct unsolved matrix!" << std::endl;
    }
    return 0;
}
