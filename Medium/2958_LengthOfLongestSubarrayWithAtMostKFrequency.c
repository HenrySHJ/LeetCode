# include <stdio.h>
# include <stdlib.h>

int maxSubarrayLength(int* nums, int numsSize, int k) {
    int p1 = 0;
    int p2 = 0;

    int max_num = 0; 
    for (int idx = 0; idx < numsSize; idx++) {
        if (nums[idx] > max_num) {
            max_num = nums[idx];
        }
    }
    int* freq = (int*)calloc(max_num + 1, sizeof(int));

    int ans = 0;
    while (p1 < numsSize && p2 < numsSize) {
        
        if (freq[nums[p2]] == k) {
            while (freq[nums[p2]] == k)
                freq[nums[p1++]]--;
        }

        else {
            freq[nums[p2++]]++;
        }

        if (ans < p2 - p1)
            ans = p2 - p1;
    }

    free(freq);
    return ans;
}