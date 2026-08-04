# include <stdio.h>
# include <stdlib.h>

int max(int a, int b) {
    if (a <= b) return b;
    else return a;
}

int maxCoins(int* nums, int numsSize) {
    // New array with adding value 1 on side
    int n = numsSize + 2;
    int val[n];
    val[0] = 1;
    val[n - 1] = 1;
    for (int i = 0; i < numsSize; i++) 
        val[i + 1] = nums[i];
    
    // Initialize dp table : dp[i][j] = leaving i and j and bursting all
    int dp[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) 
            dp[i][j] = 0;
    }

    // Topological Order : By longer range
    for (int len = 2; len < n; len++) {
        for (int s = 0; s < n - len; s++) {
            int e = s + len; 

            for (int m = s + 1; m < e; m++) {
                int coin = val[s] * val[m] * val[e];
                int total = dp[s][m] + dp[m][e] + coin;
                
                dp[s][e] = max(dp[s][e], total);
            }
        }
    }

    return dp[0][n - 1];
}