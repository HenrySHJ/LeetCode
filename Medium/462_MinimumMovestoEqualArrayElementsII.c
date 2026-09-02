# include <stdio.h>
# include <stdlib.h>

int compare(const void* a, const void* b) {
    int num1 = *(int*)a;
    int num2 = *(int*)b;
    return (num1 > num2) - (num1 < num2);
}

int minMoves2(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);
    int med = nums[numsSize / 2];

    int ans = 0;
    for (int i = 0; i < numsSize; i++) 
        ans += abs(med - nums[i]);

    return ans;
}