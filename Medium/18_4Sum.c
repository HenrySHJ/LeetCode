# include <stdio.h>
# include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int compare(const void* a, const void* b) {
    int num1 = *(const int*)a;
    int num2 = *(const int*)b;
    return (num1 > num2) - (num1 < num2);
}

int capacity = 2;
int** ans;

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), compare);
    ans = (int**)malloc(capacity * sizeof(int*));
    int count = 0;

    for (int i = 0; i < numsSize - 3; i++) {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        for (int j = i + 1; j < numsSize - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;

            int l = j + 1;
            int r = numsSize - 1;

            while (l < r) {
                long long sum = (long long)nums[i] + nums[j] + nums[l] + nums[r];
                if (sum == target) {
                    ans[count] = (int*)malloc(4 * sizeof(int));
                    ans[count][0] = nums[i];
                    ans[count][1] = nums[j];
                    ans[count][2] = nums[l];
                    ans[count][3] = nums[r];
                    count++;

                    if (count >= capacity) {
                        capacity *= 2;
                        ans = (int**)realloc(ans, capacity * sizeof(int*));
                    }

                    while (l < r && nums[l] == nums[l + 1]) l++;
                    while (l < r && nums[r] == nums[r - 1]) r--;
                    l++;
                    r--;
                }

                else if (sum < target)
                    l++;
                else
                    r--;
            }
        }
    }
    *returnSize = count;
    *returnColumnSizes = (int*)malloc(count * sizeof(int));
    for (int i = 0; i < count; i++)
        (*returnColumnSizes)[i] = 4;
    return ans;
}