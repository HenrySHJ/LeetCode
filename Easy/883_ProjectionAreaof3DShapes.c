# include <stdio.h>
# include <stdlib.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int projectionArea(int** grid, int gridSize, int* gridColSize) {
    int n = gridSize;
    int xy = 0;
    int xz = 0;
    int yz = 0;

    for (int i = 0; i < n; i++) {
        int max_xz = 0;
        int max_yz = 0;
        for (int j = 0; j < n; j++) {
            if (grid[i][j])
                xy++;
            max_xz = max(max_xz, grid[i][j]);
            max_yz = max(max_yz, grid[j][i]);
        }
        xz += max_xz;
        yz += max_yz;
    }

    return xy + xz + yz;
}