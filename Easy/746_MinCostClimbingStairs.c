# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# define INF INT_MAX

int min(int a, int b) {
    if (a <= b) return a;
    else return b;
}

int minCostClimbingStairs(int* cost, int costSize) {
    // Initialize dp
    int* dp = (int*)malloc(costSize * sizeof(int));
    for (int i = 2; i < costSize; i++)
        dp[i] = INF;

    // Set base case
    dp[0] = cost[0];
    dp[1] = cost[1];

    for (int i = 2; i < costSize; i++) {
        dp[i] = min(dp[i - 2], dp[i - 1]) + cost[i];
    }

    int ans = min(dp[costSize - 2], dp[costSize - 1]);
    free(dp);
    return ans;
}