# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

long long ans;

void create(int* nums, int numsSize, int index, long long strength, int count) {
    if (count > 0 && strength > ans)
        ans = strength;

    if (index == numsSize)
        return;

    create(nums, numsSize, index + 1, strength * nums[index], count + 1);
    create(nums, numsSize, index + 1, strength, count);
}

long long maxStrength(int* nums, int numsSize) {
    ans = LLONG_MIN;
    create(nums, numsSize, 0, 1, 0);

    return ans;
}

