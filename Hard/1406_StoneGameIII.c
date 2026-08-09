# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>

int max(int a, int b) {
    return (a < b) ? b : a;
}
int* dp;
int* suffix;

int solve(int i, int n) {
    // Base case
    if (i >= n)
        return 0;

    // Memoization
    if (dp[i] != -INT_MAX)
        return dp[i];

    int ans = -INT_MAX;
    for (int X = 1; X <= 3; X++) 
        if (i + X <= n) {
            int total = suffix[i] - suffix[i + X] - solve(i + X, n);
            ans = max(ans, total);
        }
    dp[i] = ans;
    return dp[i];
}

char* stoneGameIII(int* stoneValue, int stoneValueSize) {
    int n = stoneValueSize;

    // Initialize dp table
    dp = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        dp[i] = -INT_MAX;
    
    // Initialize suffix array
    suffix = (int*)malloc((n + 1) * sizeof(int));
    suffix[n] = 0;
    for (int i = n - 1; i >= 0; i--) 
        suffix[i] = stoneValue[i] + suffix[i + 1];
    
    int ans = solve(0, n);

    free(suffix);
    free(dp);
    
    if (ans > 0)
        return "Alice";
    else if (ans < 0)
        return "Bob";
    return "Tie";
}
