#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char*** results;
int resCount;

void solve(char** board, int r, int n, bool* col_check, bool* diag1, bool* diag2) {
    // N Queens -> add answer
    if (r == n) {
        results[resCount] = (char**)malloc(n * sizeof(char*));
        for (int i = 0; i < n; i++) {
            results[resCount][i] = (char*)malloc((n + 1) * sizeof(char));
            strcpy(results[resCount][i], board[i]);
        }
        resCount++;
        return;
    }

    for (int c = 0; c < n; c++) {
        // Checking column and diagonal
        if (!col_check[c] && !diag1[r + c] && !diag2[r - c + n]) {
            // Place Queen
            board[r][c] = 'Q';
            col_check[c] = diag1[r + c] = diag2[r - c + n] = true;

            // Search next Row
            solve(board, r + 1, n, col_check, diag1, diag2);

            // Remove Queen (BackTracking)
            board[r][c] = '.';
            col_check[c] = diag1[r + c] = diag2[r - c + n] = false;
        }
    }
}

char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes) {
    results = (char***)malloc(500 * sizeof(char**));
    resCount = 0;

    // Initializing Chess board
    char** board = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        board[i] = (char*)malloc((n + 1) * sizeof(char));
        for (int j = 0; j < n; j++) {
            board[i][j] = '.';
        }
        board[i][n] = '\0';
    }
    
    // Initializing Check array
    bool* col_check = (bool*)calloc(n, sizeof(bool));
    bool* diag1 = (bool*)calloc(n * 2 + 1, sizeof(bool));
    bool* diag2 = (bool*)calloc(n * 2 + 1, sizeof(bool));

    // Start solving
    solve(board, 0, n, col_check, diag1, diag2);

    // Returning sizes
    *returnSize = resCount;
    *returnColumnSizes = (int*)malloc(resCount * sizeof(int));
    for (int i = 0; i < resCount; i++) {
        (*returnColumnSizes)[i] = n; 
    }

    // Free memory
    for (int i = 0; i < n; i++) 
        free(board[i]);
    free(board);
    free(col_check);
    free(diag1);
    free(diag2);

    return results;
}