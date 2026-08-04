# include <stdio.h>
# include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* ans;
int capacity;

int compare(const void *a, const void *b) {
    int num1 = *(int *)a;
    int num2 = *(int *)b;
    
    return num1 - num2;
}

int* findMissingElements(int* nums, int numsSize, int* returnSize) {
    capacity = 2;
    int* ans = (int*)malloc(capacity * sizeof(int));
    int count = 0;

    qsort(nums, numsSize, sizeof(int), compare);

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > nums[i - 1] + 1) {
            for (int j = nums[i - 1] + 1; j < nums[i]; j++) {
                ans[count++] = j;

                if (count >= capacity) {
                    capacity *= 2;
                    ans = (int*)realloc(ans, capacity * sizeof(int));
                }
            }
        }
    }
    *returnSize = count;
    return ans;
}