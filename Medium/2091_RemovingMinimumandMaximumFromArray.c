# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int minimumDeletions(int* nums, int numsSize) {
    int minIdx = -1;
    int minNum = INT_MAX;
    int maxIdx = -1;
    int maxNum = INT_MIN;

    for (int i = 0; i < numsSize; i++) {
        if (minNum > nums[i]) {
            minNum = nums[i];
            minIdx = i;
        }
        if (maxNum < nums[i]) {
            maxNum = nums[i];
            maxIdx = i;
        }
    }

    int ans = numsSize;
    int l = min(minIdx, maxIdx);
    int r = max(minIdx, maxIdx);

    ans = min(r + 1, numsSize - l);
    ans = min(ans, l + 1 + numsSize - r);

    return ans;
}
