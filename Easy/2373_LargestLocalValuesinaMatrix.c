# include <stdio.h>
# include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int max(int a, int b) {
    return a > b ? a : b;
}

int** largestLocal(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes) {
    int m = gridSize;
    int n = gridColSize[0];

    int rowMax[m][n - 2];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - 2; j++) 
            rowMax[i][j] = max(grid[i][j], max(grid[i][j + 1], grid[i][j + 2]));
    }

    int** maxLocal = (int**)malloc((m - 2) * sizeof(int*));
    for (int i = 0; i < m - 2; i++) {
        maxLocal[i] = (int*)malloc((n - 2) * sizeof(int));
        for (int j = 0; j < n - 2; j++) 
            maxLocal[i][j] = max(rowMax[i][j], max(rowMax[i + 1][j], rowMax[i + 2][j]));
    }

    *returnSize = m - 2;
    *returnColumnSizes = (int*)malloc((m - 2) * sizeof(int));
    for (int i = 0; i < m - 2; i++) 
        (*returnColumnSizes)[i] = n - 2;

    return maxLocal;
}