# include <stdio.h>
# include <stdlib.h>

int max(int a, int b) {
    if (a > b) return a;
    else return b;
}

int rob(int* nums, int numsSize) {
    int dp[numsSize];
    dp[0] = nums[0];
    if (numsSize >= 2)
        dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < numsSize; i++) {
        dp[i] = 0;
        dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
    }

    return dp[numsSize - 1];
}