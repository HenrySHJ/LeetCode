# include <stdio.h>
# include <stdlib.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int firstStableIndex(int* nums, int numsSize, int k) {
    int prefix[numsSize];
    int suffix[numsSize];
    
    prefix[0] = nums[0];
    for (int i = 1; i < numsSize; i++) 
        prefix[i] = max(prefix[i - 1], nums[i]);

    suffix[numsSize - 1] = nums[numsSize - 1];
    for (int i = numsSize - 2; i >= 0; i--) 
        suffix[i] = min(suffix[i + 1], nums[i]);

    for (int i = 0; i < numsSize; i++) {
        int score = prefix[i] - suffix[i];

        if (score <= k)
            return i;
    }

    return -1;
}
