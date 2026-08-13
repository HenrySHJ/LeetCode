// Solution 1 : Sorting
# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>

int compare(const void* a, const void* b) {
    int num1 = *(const int*)a;
    int num2 = *(const int*)b;
    return (num1 > num2) - (num1 < num2);
}

bool containsDuplicate(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);

    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            return true;
        }
    }

    return false;
}