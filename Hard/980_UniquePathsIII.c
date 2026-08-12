# include <stdio.h>
# include <stdlib.h>

int ans;
int empty;

void dfs(int** grid, int m, int n, int x, int y, int count) {
    // Checking Valid index
    if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == -1)
        return;

    // Found the ending square
    if (grid[x][y] == 2) {
        if (empty == count)
            ans++;
        return;
    }

    grid[x][y] = -1;

    dfs(grid, m, n, x + 1, y, count + 1);
    dfs(grid, m, n, x - 1, y, count + 1);
    dfs(grid, m, n, x, y + 1, count + 1);
    dfs(grid, m, n, x, y - 1, count + 1);
    
    // backtrack
    grid[x][y] = 0;
}   

int uniquePathsIII(int** grid, int gridSize, int* gridColSize) {
    ans = 0;
    empty = 1;
    int m = gridSize;
    int n = gridColSize[0];

    int x, y;

    // Finding start/end point
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                x = i;
                y = j;
            } 
            else if (grid[i][j] == 0)
                empty++;
        }
    }

    dfs(grid, m, n, x, y, 0);

    return ans;
}