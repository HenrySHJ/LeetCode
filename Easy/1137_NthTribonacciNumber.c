# include <stdio.h>
# include <stdlib.h>

int tribonacci(int n) {
    int* dp = (int*)calloc(n + 1, sizeof(int));
    dp[0] = 0;
    if (n >= 1) dp[1] = 1;
    if (n >= 2) dp[2] = 1;

    for (int i = 3; i < n + 1; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    int ans = dp[n];
    free(dp);
    return ans;
}