# include <stdio.h>
# include <stdlib.h>

int compare(const void *a, const void *b) {
    int num1 = *(const int*)a;
    int num2 = *(const int*)b;
    
    if (num1 < num2) return -1;
    else if (num1 > num2) return 1;
    else return 0;
}

int largestPerimeter(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);

    int ans = 0;
    for (int i = numsSize - 3; i >= 0; i--) {
        if (nums[i] + nums[i + 1] > nums[i + 2]) {
            ans = nums[i] + nums[i + 1] + nums[i + 2];
            break;
        }
    }
    return ans;
}