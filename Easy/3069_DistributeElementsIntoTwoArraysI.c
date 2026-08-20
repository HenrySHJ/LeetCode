# include <stdio.h>
# include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* resultArray(int* nums, int numsSize, int* returnSize) {
    int n = numsSize;
    int* arr1 = (int*)malloc(n * sizeof(int));
    int* arr2 = (int*)malloc(n * sizeof(int));

    arr1[0] = nums[0];
    arr2[0] = nums[1];
    int idx1 = 1;
    int idx2 = 1;

    for (int i = 2; i < numsSize; i++) {
        if (arr1[idx1 - 1] > arr2[idx2 - 1]) 
            arr1[idx1++] = nums[i];
        
        else
            arr2[idx2++] = nums[i];
    }

    // Concat
    for (int i = 0; i < idx2; i++) {
        arr1[idx1++] = arr2[i];
    }

    *returnSize = n;
    return arr1;
}