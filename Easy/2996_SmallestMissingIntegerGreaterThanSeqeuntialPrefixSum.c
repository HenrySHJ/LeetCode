# include <stdio.h>
# include <stdbool.h>

int missingInteger(int* nums, int numsSize) {
    int sum = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i - 1] + 1) 
            sum += nums[i];
        else 
            break; 
    }

    int ans = sum;
    while (1) {
        bool flag = false;

        for (int i = 0; i < numsSize; i++) {
            if (nums[i] == ans) {
                flag = true;
                break;
            }
        }
        
        if (flag) 
            ans++;
        else 
            break;
    }

    return ans;
}