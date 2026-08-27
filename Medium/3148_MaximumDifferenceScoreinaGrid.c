# include <stdio.h>
# include <stdlib.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int maxScore(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];

    // Initialize dp table
    int dp[m + 1][n + 1];
    for (int i = 0; i < m + 1; i++)
        dp[i][0] = INT_MAX;
    for (int j = 0; j < n + 1; j++)
        dp[0][j] = INT_MAX;

    int ans = INT_MIN;

    for (int i = 1; i < m + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            int cand = min(dp[i][j - 1], dp[i - 1][j]);
            dp[i][j] = min(grid[i - 1][j - 1], cand);
            ans = max(ans, grid[i - 1][j - 1] - cand);
        }
    }

    return ans;
}