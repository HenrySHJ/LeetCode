# include <stdio.h>
# include <stdlib.h>

int max(int a, int b) {
    if (a > b) return a;
    else return b;
}
int maxSubArray(int* nums, int numsSize) {
    int max_sum = -INFINITY;
    int cur_sum = 0;

    for (int i = 0; i < numsSize; i++) 
        if (cur_sum + nums[i] > 0) {
            max_sum = max(max_sum, cur_sum + nums[i]);
            cur_sum = cur_sum + nums[i];
        }
        else {
            max_sum = max(max_sum, nums[i]);
            cur_sum = 0;
        }    
    
    return max_sum;
}