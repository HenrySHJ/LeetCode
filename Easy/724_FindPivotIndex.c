# include <stdio.h>
# include <stdlib.h>

int pivotIndex(int* nums, int numsSize) {
    int n = numsSize;

    int prefixSum[n + 2];
    prefixSum[0] = 0;
    for (int i = 1; i < n + 1; i++) 
        prefixSum[i] = prefixSum[i - 1] + nums[i - 1];

    int suffixSum[n + 2];
    suffixSum[n + 1] = 0;
    for (int i = n; i >= 1; i--) 
        suffixSum[i] = suffixSum[i + 1] + nums[i - 1];

    for (int i = 1; i <= n; i++) {
        if (prefixSum[i - 1] == suffixSum[i + 1])
            return i - 1;
    }

    return -1;
}
