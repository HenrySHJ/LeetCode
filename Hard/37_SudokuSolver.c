#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char** ans;

bool checkRow(int x, int target) {
    for (int j = 0; j < 9; j++) {
        if (ans[x][j] - '0' == target)
            return false;
    }
    return true;
}

bool checkCol(int y, int target) {
    for (int i = 0; i < 9; i++) {
        if (ans[i][y] - '0' == target)
            return false;
    }
    return true;
}

bool checkBox(int x, int y, int target) {
    int startX = (x / 3) * 3;
    int startY = (y / 3) * 3;
    for (int i = startX; i < startX + 3; i++) {
        for (int j = startY; j < startY + 3; j++) {
            if (ans[i][j] - '0' == target)
                return false;
        }
    }
    return true;
}

bool dfs(int x, int y) {
    if (x == 9)
        return true;

    // Filing Row first 
    int nextX = (y == 8) ? x + 1 : x;
    int nextY = (y == 8) ? 0 : y + 1;

    // Try if the original board was empty
    if (ans[x][y] != '.') {
        return dfs(nextX, nextY);
    }

    for (int i = 1; i <= 9; i++) {
        if (!checkRow(x, i)) 
            continue;
        if (!checkCol(y, i)) 
            continue;
        if (!checkBox(x, y, i)) 
            continue;

        ans[x][y] = '0' + i; 

        if (dfs(nextX, nextY))
            return true; 

        ans[x][y] = '.'; 
    }

    return false;
}

void solveSudoku(char** board, int boardSize, int* boardColSize) {
    ans = board;

    dfs(0, 0);
}