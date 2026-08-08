# include <stdio.h>
# include <stdlib.h>

int min(int a, int b) {
    if (a < b) return a;
    else return b;
}

int max(int a, int b) {
    if (a > b) return a;
    else return b;
}

int maximumScore(int* nums, int numsSize, int k) {
    int i = k;
    int j = k;

    int min_val = nums[k];
    int ans = nums[k];

    while (i > 0 && j < numsSize - 1) {
        if (nums[i - 1] < nums[j + 1]) {
            if (nums[j + 1] < min_val) 
                min_val = nums[j + 1];
    
            ans = max(ans, min_val * (j - i + 2));
            j++;
        }
        else {
            if (nums[i - 1] < min_val)
                min_val = nums[i - 1];
            
            ans = max(ans, min_val * (j - i + 2));
            i--;
        }
    }

    while (i > 0) {
        if (nums[i - 1] < min_val)
            min_val = nums[i - 1];
            
        ans = max(ans, min_val * (j - i + 2));
        i--;
    }

    while (j < numsSize - 1) {
        if (nums[j + 1] < min_val)
            min_val = nums[j + 1];

        ans = max(ans, min_val * (j - i + 2));
        j++;
    }

    return ans;
}
