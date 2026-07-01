# include <stdio.h>
# include <stdlib.h>

int change(int amount, int* coins, int coinsSize) {
    unsigned int* dp = (int*)calloc(amount + 1, sizeof(int));      
    dp[0] = 1;

    // fill dp table
    for (int c = 0; c < coinsSize; c++) {
        int coin = coins[c];
        
        if (coin > amount) continue;

        for (int i = coin; i <= amount; i++) {
            dp[i] += dp[i - coin];
        }
    }
    int ans = dp[amount];
    free(dp);
    return ans;
}

