# include <stdio.h>
# include <stdlib.h>

int numberOfArithmeticSlices(int* nums, int numsSize) {
    int cur = 0;
    int sum = 0;

    for (int i = 2; i < numsSize; i++) {
        if (nums[i - 1] - nums[i - 2] == nums[i] - nums[i - 1]) {
            cur++;
            sum += cur;
        }
        else {
            cur = 0;
        }
    }

    return sum;
}