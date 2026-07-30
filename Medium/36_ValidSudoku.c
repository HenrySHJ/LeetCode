# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>

char** sudoku;

bool checkRow(int row) {
    bool check[10] = {false};

    for (int j = 0; j < 9; j++) {
        if (sudoku[row][j] >= '1' && sudoku[row][j] <= '9') {
            int num = sudoku[row][j] - '0';

            if (check[num] == true)
                return false;

            check[num] = true;
        }
    }
    return true;
}

bool checkCol(int col) {
    bool check[10] = {false};

    for (int i = 0; i < 9; i++) {
        if (sudoku[i][col] >= '1' && sudoku[i][col] <= '9') {
            int num = sudoku[i][col] - '0';

            if (check[num] == true)
                return false;

            check[num] = true;
        }
    }
    return true;
}

bool checkBox(int row, int col) {
    bool check[10] = {false};

    for (int i = row; i < row + 3; i++) {
        for (int j = col; j < col + 3; j++) {
            if (sudoku[i][j] >= '1' && sudoku[i][j] <= '9') {
                int num = sudoku[i][j] - '0';

                if (check[num] == true)
                    return false;

                check[num] = true;
            }
        }
    }
    return true;
}

bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    sudoku = board;
    for (int i = 0; i < 9; i++) {
        if (!checkRow(i))
            return false;
    }

    for (int j = 0; j < 9; j++) {
        if (!checkCol(j))
            return false;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            if (!checkBox(i * 3, j * 3))
                return false;
    }

    return true;
}