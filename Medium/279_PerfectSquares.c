# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

int min(int a, int b) {
    if (a <= b) return a;
    else return b;
}

int numSquares(int n) {
    // dp[i] : least ways to make i
    int* dp = (int*)calloc(n + 1, sizeof(int));
    for (int i = 1; i < n + 1; i++) 
        dp[i] = i;
    
    // setting base case
    int num = 1;
    while (num * num <= n) {
        dp[num * num] = 1;
        num++;
    }

    // divide into two sqare numbers
    for (int s = 1; s < num + 1; s++) {
        for (int i = s * s; i < n + 1; i++) 
            dp[i] = min(dp[i], dp[i - s * s] + 1);
    }
    return dp[n];
}