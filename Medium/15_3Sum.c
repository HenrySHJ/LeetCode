# include <stdio.h>
# include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int compare(const void *a, const void *b) {
    int num1 = *(const int *)a;
    int num2 = *(const int *)b;

    if (num1 < num2) return -1;
    if (num1 > num2) return 1;
    return 0;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    // Preprocessing : sort arrays by ascending order
    qsort(nums, numsSize, sizeof(int), compare);
    
    // Malloc answer
    int capacity = 64;
    int** ans = (int**)malloc(capacity * sizeof(int*));
    int idx = 0;

    for (int i = 0; i < numsSize; i++) {
        // Avoid Duplicate
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        // Two Pointers
        int j = i + 1;
        int k = numsSize - 1;

        while (j < k) {
            int total = nums[i] + nums[j] + nums[k];

            if (total > 0) {
                k--;
            }
            else if (total < 0) {
                j++;
            }
            else {
                int* triplet = (int*)malloc(3 * sizeof(int));
                triplet[0] = nums[i];
                triplet[1] = nums[j];
                triplet[2] = nums[k];

                if (idx >= capacity) {
                    capacity *= 2;
                    ans = (int**)realloc(ans, capacity * sizeof(int*));
                }

                ans[idx++] = triplet;
                j++;

                while (nums[j] == nums[j - 1] && j < k) {
                    j++;
                }
            }
        }
    }
    *returnSize = idx;
    *returnColumnSizes = (int*)malloc(idx * sizeof(int));
    for (int i = 0; i < idx; i++) {
        (*returnColumnSizes)[i] = 3;
    }
    return ans;
}