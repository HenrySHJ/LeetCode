# include <stdio.h>
# include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* shuffle(int* nums, int numsSize, int n, int* returnSize){
    int ans2[n];
    for (int i = n; i < numsSize; i++) 
        ans2[i - n] = nums[i];
    
    for (int i = numsSize - 2; i >= 0; i -= 2) 
        nums[i] = nums[i / 2];

    for (int i = 1; i < numsSize; i += 2) 
        nums[i] = ans2[i / 2];
    
    *returnSize = numsSize;
    return nums;
}