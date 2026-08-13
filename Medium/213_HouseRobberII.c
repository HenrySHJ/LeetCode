# include <stdio.h>
# include <stdlib.h>

int max(int a, int b) {
    if (a >= b) return a;
    else return b;
}

int rob(int* nums, int numsSize) {
    int dp1[numsSize];
    int dp2[numsSize];
    dp1[0] = nums[0];
    
    if (numsSize >= 2) {
        dp1[1] = max(nums[0], nums[1]);
        dp2[1] = nums[1];
    }

    if (numsSize >= 3) {
        dp2[2] = max(nums[1], nums[2]);
    }

    for (int i = 2; i < numsSize - 1; i++) {
        dp1[i] = max(dp1[i - 2] + nums[i], dp1[i - 1]);
    }
    for (int i = 3; i < numsSize; i++) {
        dp2[i] = max(dp2[i - 2] + nums[i], dp2[i - 1]);
    }

    return max((numsSize >= 2 ? dp1[numsSize - 2] : nums[0]), dp2[numsSize - 1]);
}