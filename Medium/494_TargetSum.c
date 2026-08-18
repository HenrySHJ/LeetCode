# include <stdio.h>
# include <stdlib.h>

// Solution 1 : Backtracking
int ans;

void dfs(int* nums, int idx, int numsSize, int sum, int target) {
    if (idx == numsSize) {
        if (sum == target) 
            ans++;
        return;
    }

    dfs(nums, idx + 1, numsSize, sum + nums[idx], target);
    dfs(nums, idx + 1, numsSize, sum - nums[idx], target);
}

int findTargetSumWays(int* nums, int numsSize, int target) {
    ans = 0;

    dfs(nums, 0, numsSize, 0, target);

    return ans;
}

// Solution 2 : 0-1 Knapsack DP
int findTargetSumWays(int* nums, int numsSize, int target) {
    int totalSum = 0;
    for (int i = 0; i < numsSize; i++) 
        totalSum += nums[i];

    if (abs(target) > totalSum || (target + totalSum) % 2 != 0 || (target + totalSum) < 0) {
        return 0;
    }

    int subsetSum = (target + totalSum) / 2;

    int* dp = (int*)calloc(subsetSum + 1, sizeof(int));
    dp[0] = 1;

    for (int i = 0; i < numsSize; i++) {
        for (int j = subsetSum; j >= nums[i]; j--) {
            dp[j] += dp[j - nums[i]];
        }
    }

    int result = dp[subsetSum];
    free(dp);

    return result;
}