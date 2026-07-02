# include <stdio.h>
# include <stdlib.h>

int max(int a, int b) {
    if (a <= b) return b;
    else return a;
}

int maxProfit(int* prices, int pricesSize) {
    // dp[i] : max profit of day
    int* dp = (int*)calloc(pricesSize, sizeof(int));

    for (int i = 1; i < pricesSize; i++) {
        dp[i] = max(dp[i - 1], dp[i - 1] + prices[i] - prices[i - 1]);
    }
    int ans = dp[pricesSize - 1];
    free(dp);

    return ans;
}