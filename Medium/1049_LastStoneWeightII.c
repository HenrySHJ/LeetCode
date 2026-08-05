# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

int lastStoneWeightII(int* stones, int stonesSize) {
    int sum = 0;
    for (int i = 0; i < stonesSize; i++) {
        sum += stones[i];
    }

    int target = sum / 2;
    int dp[target + 1];
    memset(dp, 0, sizeof(dp));

    // 0/1 Knapsack DP
    for (int i = 0; i < stonesSize; i++) {
        int weight = stones[i];
        for (int w = target; w >= weight; w--) {
            dp[w] = MAX(dp[w], dp[w - weight] + weight);
        }
    }

    return sum - 2 * dp[target];
}