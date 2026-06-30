# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# define INF INT_MAX

int min(int a, int b) {
    if (a <= b) return a;
    else return b;
}
int coinChange(int* coins, int coinsSize, int amount) {
    // dp[i] : fewest count to make i
    int* dp = (int*)malloc((amount + 1) * sizeof(int));
    for (int i = 0; i <= amount; i++) 
        dp[i] = INF;

    // Set Base case
    dp[0] = 0;    

    // Trying every coin
    for (int c = 0; c < coinsSize; c++) {
        // Fill dp table by topological order
        for (int i = coins[c]; i <= amount; i++) {
            if (dp[i - coins[c]] != INF) {
                dp[i] = min(dp[i], dp[i - coins[c]] + 1);
            }
        }
    }

    int ans = dp[amount];
    free(dp);

    return (ans == INF) ? -1 : ans;
}