# include <stdio.h>
# include <stdlib.h>

int dp[70][70][70];

int max(int a, int b) {
    return (a > b) ? a : b;
}

int pickup(int** grid, int n, int m, int row, int c1, int c2) {
    // Reached final row
    if (row == n) 
        return 0;

    // Checking if index is valid
    if (c1 < 0 || c1 >= m || c2 < 0 || c2 >= m)
        return 0;

    // Memoization
    if (dp[row][c1][c2] != -1) 
        return dp[row][c1][c2];

    // Moving cells
    int pick = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int p1 = pickup(grid, n, m, row + 1, c1 + i, c2 + j);
            pick = max(pick, p1);
        }
    }

    dp[row][c1][c2] = pick + ((c1 != c2) ? grid[row][c1] + grid[row][c2] : grid[row][c1]);
    return dp[row][c1][c2];
}

int cherryPickup(int** grid, int gridSize, int* gridColSize) {
    int n = gridSize;
    int m = gridColSize[0];

    memset(dp, -1, sizeof(dp));

    int ans = pickup(grid, n, m, 0, 0, m - 1);
    return ans;
}