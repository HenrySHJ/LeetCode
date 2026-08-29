# include <stdio.h>
# include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void backtrack(int* nums, int numsSize, int start, int* path, int pathSize, 
               int** result, int* returnSize, int** returnColumnSizes) {
    
    result[*returnSize] = (int*)malloc(pathSize * sizeof(int));
    for (int i = 0; i < pathSize; i++) 
        result[*returnSize][i] = path[i];
    
    (*returnColumnSizes)[*returnSize] = pathSize;
    (*returnSize)++;

    for (int i = start; i < numsSize; i++) {
        if (i > start && nums[i] == nums[i - 1]) 
            continue;

        path[pathSize] = nums[i];
        backtrack(nums, numsSize, i + 1, path, pathSize + 1, result, returnSize,returnColumnSizes);
    }
}

int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), compare);

    int capacity = 1 << numsSize; 
    int** ans = (int**)malloc(capacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));
    *returnSize = 0;

    int* path = (int*)malloc(numsSize * sizeof(int));

    backtrack(nums, numsSize, 0, path, 0, ans, returnSize, returnColumnSizes);

    free(path);
    return ans;
}
