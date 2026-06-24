# include <stdio.h>
# include <stdlib.h>

int* findDegrees(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int* degree = (int*)calloc(matrixSize, sizeof(int));

    for (int i = 0; i < matrixSize; i++) {
        for (int j = i + 1; j < matrixColSize[i]; j++) 
            if (matrix[i][j] == 1) {
                degree[i]++;
                degree[j]++;
            }
    }

    *returnSize = matrixSize;
    return degree;
}