# include <stdio.h>
# include <stdlib.h>

int missingMultiple(int* nums, int numsSize, int k) {
    int n = numsSize;
    bool found[101];
    for (int i = 1; i < 101; i++)
        found[i] = false;

    
    for (int i = 0; i < n; i++) {
        if (nums[i] % k != 0)
            continue;

        found[nums[i] / k] = true;
    }

    for (int i = 1; i < 101; i++) {
        if (!found[i])
            return i * k;
    }
    return 101;
}