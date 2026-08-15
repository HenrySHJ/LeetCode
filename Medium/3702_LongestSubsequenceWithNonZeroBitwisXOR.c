# include <stdio.h>
# include <stdlib.h>

int longestSubsequence(int* nums, int numsSize) {
    int ans = 0;
    bool allzero = true;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0)
            allzero = false;
        ans ^= nums[i];
    }

    if (allzero)
        return 0;
        
    if (ans != 0)
        return numsSize;
    else return numsSize - 1;
}
