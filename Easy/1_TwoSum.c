# include <stdio.h>
# include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int sum = 0;

    int* arr = (int *)malloc(sizeof(int) * 2);

    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            sum = nums[i] + nums[j];

            if (sum == target) {
                arr[0] = i;
                arr[1] = j;
                return arr;
            }
        }
    }
    return NULL;
}
