# include <stdio.h>
# include <stdlib.h>

int max(int a, int b) {
    if (a < b) return b;
    else return a;
}
int lengthOfLIS(int* nums, int numsSize) {
    // dp[i] : LCS length in 0 ~ i
    int* dp = (int*)malloc(numsSize * sizeof(int));

    // Filling dp table
    for (int i = 0; i < numsSize; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    int ans = dp[numsSize - 1];
    free(dp);
    return ans;
}