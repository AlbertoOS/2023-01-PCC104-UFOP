#include "06-backtracking-algorithms.h"

bool is_sudoku_valid(int sudoku_board[sudoku_size][sudoku_size], int row, int col, int num) {
    for (int i = 0; i < sudoku_size; i++) {
        if (sudoku_board[row][i] == num)
            return false;
    }

    for (int i = 0; i < sudoku_size; i++) {
        if (sudoku_board[i][col] == num)
            return false;
    }

    int startRow = row - row % sudoku_subsize;
    int startCol = col - col % sudoku_subsize;
    for (int i = 0; i < sudoku_subsize; i++) {
        for (int j = 0; j < sudoku_subsize; j++) {
            if (sudoku_board[startRow + i][startCol + j] == num)
                return false;
        }
    }

    return true;
}

bool sudoku_find_empty_cell(int sudoku_board[sudoku_size][sudoku_size], int &row, int &col) {
    for (row = 0; row < sudoku_size; row++) {
        for (col = 0; col < sudoku_size; col++) {
            if (sudoku_board[row][col] == 0)
                return true;
        }
    }
    return false;
}

bool solve_sudoku(int sudoku_board[sudoku_size][sudoku_size]) {
    int row, col;
    if (!sudoku_find_empty_cell(sudoku_board, row, col))
        return true;

    for (int num = 1; num <= 9; ++num) {
        if (is_sudoku_valid(sudoku_board, row, col, num)) {
            sudoku_board[row][col] = num;

            if (solve_sudoku(sudoku_board))
                return true;

            sudoku_board[row][col] = 0;
            //Backtrack if solution is not found
        }
    }

    return false;
}
