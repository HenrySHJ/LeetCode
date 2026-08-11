# include <stdio.h>
# include <stdlib.h>
# define MOD 1000000007

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int dfs(int** grid, int m, int n, int x, int y, int** dp) {
    // Memoization
    if (dp[x][y] != 0)
        return dp[x][y];

    // Setting base case (length 1)
    dp[x][y] = 1;

    // Moving WASD direction
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];

        // Checking valid index
        if ((0 <= nx && nx < m) && (0 <= ny && ny < n)) {
            // Move if Path strictly increases
            if (grid[nx][ny] > grid[x][y])
                dp[x][y] = (dp[x][y] + dfs(grid, m, n, nx, ny, dp)) % MOD;
        }
    }

    return dp[x][y];
}

int countPaths(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];

    // Initialize dp table
    int** dp = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) 
        dp[i] = (int*)calloc(n, sizeof(int));
    
    int ans = 0;
    for (int x = 0; x < m; x++) {
        for (int y = 0; y < n; y++) 
            ans = (ans + dfs(grid, m, n, x, y, dp)) % MOD;
    }
    
    // Free Memory
    for (int i = 0; i < m; i++) 
        free(dp[i]);
    free(dp);

    return ans;
}