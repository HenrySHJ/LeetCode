# include <stdio.h>
# include <stdlib.h>

int min3(int a, int b, int c) {
    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    return min;
}

int maximalSquare(char** matrix, int matrixSize, int* matrixColSize) {
    int rows = matrixSize;
    int cols = matrixColSize[0];
    int ans = 0;

    // dp[i][j]
    int dp[rows + 1][cols + 1];
    for (int i = 0; i < rows + 1; i++) {
        for (int j = 0; j < cols + 1; j++) {
            dp[i][j] = 0;
        }
    }

    // Fill dp table
    for (int i = 1; i < rows + 1; i++) {
        for (int j = 1; j < cols + 1; j++) {
            if (matrix[i - 1][j - 1] == '1') {
                dp[i][j] = min3(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;   
                if (ans < dp[i][j]) 
                    ans = dp[i][j];
            }        
        }
    }

    return ans * ans;
}s