# include <stdio.h>
# include <stdlib.h>

int numTrees(int n) {
    // dp[i] : count of bst
    int* dp = (int*)malloc((n + 1) * sizeof(int));
    dp[0] = 1;
    dp[1] = 1;

    // i is root
    for (int i = 2; i < n + 1; i++) {
        dp[i] = 0;
        for (int j = 1; j <= i; j++) {
            dp[i] += dp[j - 1] * dp[i - j]; 
        }
    }

    int ans = dp[n];
    free(dp);
    return ans;
}