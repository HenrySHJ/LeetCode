# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

void solve(bool** board, int r, int n, bool* colCheck, bool* diag1, bool* diag2, int* solutions) {
    if (r == n) {
        (*solutions)++;
        return;
    }
    for (int c = 0; c < n; c++) {
        if (!colCheck[c] && !diag1[r + c] && !diag2[r - c + n]) {
            // Place Queen;
            board[r][c] = true;
            colCheck[c] = diag1[r + c] = diag2[r - c + n] = true;

            solve(board, r + 1, n, colCheck, diag1, diag2, solutions);

            // Remove Queen;
            board[r][c] = false;
            colCheck[c] = diag1[r + c] = diag2[r - c + n] = false;
        }
    }
}

int totalNQueens(int n) {
    int solutions = 0;

    // Initialize board
    bool** board = (bool**)calloc(n, sizeof(bool*));
    for (int i = 0; i < n; i++)
        board[i] = (bool*)calloc(n, sizeof(bool));
    
    // Check array for Column & Diagonal
    bool* colCheck = (bool*)calloc(n, sizeof(bool));
    bool* diag1 = (bool*)calloc(n * 2 + 1, sizeof(bool));
    bool* diag2 = (bool*)calloc(n * 2 + 1, sizeof(bool));

    solve(board, 0, n, colCheck, diag1, diag2, &solutions);
    return solutions;
}