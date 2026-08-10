#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a < b) ? b : a;
}

int stoneGameV(int* stoneValue, int stoneValueSize) {
    int n = stoneValueSize;

    // Compute prefix sum
    int prefix[n];
    prefix[0] = stoneValue[0];
    for (int i = 1; i < n; i++)
        prefix[i] = prefix[i - 1] + stoneValue[i];

    // Initialize dp table
    int dp[n][n];    
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            dp[i][j] = 0;
        }
    }        

    // Topological order by increasing length
    for (int len = 2; len < n + 1; len++) {
        for (int i = 0; i < n - len + 1; i++) {
            int j = i + len - 1;

            for (int k = i; k < j; k++) {
                int leftSum = prefix[k] - (i > 0 ? prefix[i - 1] : 0);
                int rightSum = prefix[j] - prefix[k];

                if (leftSum > rightSum) 
                    dp[i][j] = max(dp[i][j], rightSum + dp[k + 1][j]);
                else if (leftSum < rightSum)
                    dp[i][j] = max(dp[i][j], leftSum + dp[i][k]);
                else {
                    int takeLeft = leftSum + dp[i][k];
                    int takeRight = rightSum + dp[k + 1][j];
                    dp[i][j] = max(dp[i][j], max(takeLeft, takeRight));
                }
            }
        }
    }
    return dp[0][n - 1];
}