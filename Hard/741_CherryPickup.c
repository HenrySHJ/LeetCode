# include <stdio.h>
# include <stdlib.h>
# include <string.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int n;
int memo[50][50][50];

int dfs(int** grid, int r1, int c1, int r2) {
    // c2 can be calculated by other three
    int c2 = r1 + c1 - r2;
    
    // Checking valid index and walls
    if (r1 >= n || c1 >= n || r2 >= n || c2 >= n || 
        grid[r1][c1] == -1 || grid[r2][c2] == -1) {
        return -1000000;
    }

    // Found answer
    if (r1 == n - 1 && c1 == n - 1) {
        return grid[r1][c1];
    }

    // Memoization
    if (memo[r1][c1][r2] != -1) {
        return memo[r1][c1][r2];
    }

    // Checking cherries
    int cherries = 0;
    if (r1 == r2 && c1 == c2) 
        cherries = grid[r1][c1]; 
    else 
        cherries = grid[r1][c1] + grid[r2][c2];
    

    int p1 = dfs(grid, r1 + 1, c1, r2 + 1);
    int p2 = dfs(grid, r1 + 1, c1, r2);
    int p3 = dfs(grid, r1, c1 + 1, r2 + 1);
    int p4 = dfs(grid, r1, c1 + 1, r2);

    int next_max = MAX(MAX(p1, p2), MAX(p3, p4));

    if (next_max < 0) {
        return memo[r1][c1][r2] = -1000000;
    }

    return memo[r1][c1][r2] = cherries + next_max;
}

int cherryPickup(int** grid, int gridSize, int* gridColSize) {
    n = gridSize;
    memset(memo, -1, sizeof(memo));

    int result = dfs(grid, 0, 0, 0);
    return result < 0 ? 0 : result;
}