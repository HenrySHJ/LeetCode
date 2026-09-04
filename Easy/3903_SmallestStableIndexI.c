# include <stdio.h>
# include <stdlib.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int firstStableIndex(int* nums, int numsSize, int k) {
    int maxArr[numsSize];
    int minArr[numsSize];

    // preprocessing
    maxArr[0] = nums[0];
    for (int i = 1; i < numsSize; i++) 
        maxArr[i] = max(maxArr[i - 1], nums[i]);
    
    minArr[numsSize - 1] = nums[numsSize - 1];
    for (int i = numsSize - 2; i >= 0; i--) 
        minArr[i] = min(minArr[i + 1], nums[i]);
    
    for (int i = 0; i < numsSize; i++) {
        int score = maxArr[i] - minArr[i];

        if (score <= k)
            return i;
    }

    return -1;
}
