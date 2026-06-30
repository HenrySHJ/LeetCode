# include <stdio.h>
# include <stdlib.h>

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize) {
    // dp[i][j] : ways to reach i,j
    int** dp = (int**)calloc(obstacleGridSize, sizeof(int*));
    for (int i = 0; i < obstacleGridSize; i++) {
        dp[i] = (int*)calloc(obstacleGridColSize[i], sizeof(int));
    }

    for (int i = 0; i < obstacleGridSize; i++) {
        if (obstacleGrid[i][0] == 0) dp[i][0] = 1;
        else break;
    }
    for (int j = 0; j < obstacleGridColSize[0]; j++) {
        if (obstacleGrid[0][j] == 0) dp[0][j] = 1;
        else break;
    }

    for (int x = 1; x < obstacleGridSize; x++) {
        for (int y = 1; y < obstacleGridColSize[x]; y++) {
            if (obstacleGrid[x][y] == 1)
                continue;

            dp[x][y] = dp[x - 1][y] + dp[x][y - 1];;
        }
    }

    return dp[obstacleGridSize - 1][obstacleGridColSize[obstacleGridSize - 1] - 1];
}