# include <stdio.h>
# include <stdlib.h>

int min(int a, int b) {
    if (a <= b) return a;
    else return b;
}

int minPathSum(int** grid, int gridSize, int* gridColSize) {
    // Initialize total sum
    int** total = (int**)calloc(gridSize, sizeof(int*));
    for (int i = 0; i < gridSize; i++)
        total[i] = (int*)calloc(gridColSize[i], sizeof(int));
    total[0][0] = grid[0][0];

    // Base Case Setting
    for (int i = 1; i < gridSize; i++)
        total[i][0] = total[i - 1][0] + grid[i][0];
    for (int j = 1; j < gridColSize[0]; j++)
        total[0][j] = total[0][j - 1] + grid[0][j];

    // Filling by topological order
    for (int i = 1; i < gridSize; i++) {
        for (int j = 1; j < gridColSize[i]; j++) {
            total[i][j] = min(total[i - 1][j], total[i][j - 1]) + grid[i][j];
        }
    }

    int ans = total[gridSize - 1][gridColSize[0] - 1];
    free(total);
    return ans;
}