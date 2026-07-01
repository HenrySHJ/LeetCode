# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

int min(int a, int b) {
    if (a < b) return a;
    else return b;
}

int max(int a, int b) {
    if (a < b) return b;
    else return a;
}

int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) {
    // dp[i][j] : the last used index is i, j
    int** dp = (int**)calloc(triangleSize, sizeof(int*));
    for (int i = 0; i < triangleSize; i++) 
        dp[i] = (int*)calloc(triangleColSize[i], sizeof(int));
    dp[0][0] = triangle[0][0];

    // fill dp table
    for (int i = 1; i < triangleSize; i++) {
        for (int j = 0; j < triangleColSize[i]; j++) {
            if (j == 0)
                dp[i][j] = dp[i - 1][j] + triangle[i][j];
            else if (j == triangleColSize[i] - 1)
                dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
            else
                dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
        }
    }

    // find answer
    int ans = INT_MAX;
    for (int j = 0; j < triangleSize; j++) {
        ans = min(ans, dp[triangleSize - 1][j]);
    }

    // free memory
    for (int i = 0; i < triangleSize; i++)
        free(dp[i]);
    free(dp);
    return ans;
}