# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

# define MAX(a, b) (((a) > (b)) ? (a) : (b))
# define MIN(a, b) (((a) < (b)) ? (a) : (b))

int maxProduct(int* nums, int numsSize) {
    if (numsSize == 0) 
        return 0;

    int ans = nums[0]; 
    int curr_max = nums[0];   
    int curr_min = nums[0];   

    for (int i = 1; i < numsSize; i++) {
        int num = nums[i];

        if (num < 0) {
            int temp = curr_max;
            curr_max = curr_min;
            curr_min = temp;
        }

        curr_max = MAX(num, curr_max * num);
        curr_min = MIN(num, curr_min * num);

        ans = MAX(ans, curr_max);
    }

    return ans;
}