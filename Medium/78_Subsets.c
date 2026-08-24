# include <stdio.h>
# include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    // Allocate answer array
    int size = 1 << numsSize;
    *returnSize = size;

    int** ans = (int**)malloc(size * sizeof(int*));
    *returnColumnSizes = (int*)calloc(size, sizeof(int));

    // allocate by index bit count
    for (int i = 0; i < size; i++) {
        int count32 = __builtin_popcount(i);
        ans[i] = (int*)malloc(count32 * sizeof(int));
    }

    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < size; j++) {
            if ((1 << i) & j) {
                ans[j][(*returnColumnSizes)[j]] = nums[i];
                (*returnColumnSizes)[j]++;
            }
        }
    }
    
    return ans;
}