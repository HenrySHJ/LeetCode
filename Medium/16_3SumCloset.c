# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

int compare(const void* a, const void* b) {
    int num1 = *(const int*)a;
    int num2 = *(const int*)b;
    return (num1 > num2) - (num1 < num2);
}

int threeSumClosest(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), compare);
    int ans = nums[numsSize - 1] + nums[numsSize - 2] + nums[numsSize - 3];

    for (int i = 0; i < numsSize - 2; i++) {
        int l = i + 1;
        int r = numsSize - 1;

        while (l < r) {
            int sum = nums[i] + nums[l] + nums[r];

            if (abs(sum - target) < abs(target - ans))
                ans = sum;
        
            if (sum - target > 0)
                r--;
            else if (sum - target < 0)
                l++;
            else break;
        }
    }
    return ans;
}