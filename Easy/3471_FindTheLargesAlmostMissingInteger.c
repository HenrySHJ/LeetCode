# include <stdio.h>
# include <stdlib.h>

int max(int a, int b) {
    if (a <= b) return b;
    else return a;
}

int largestInteger(int* nums, int numsSize, int k) {
    int freq[51] = {0};
    if (numsSize == k) {
        int ans = 0;
        for (int i = 0; i < numsSize; i++) {
            if (ans < nums[i])
                ans = nums[i];
        }
        return ans;
    }

    if (k == 1) {
        int ans = 0;
        for (int i = 0; i < numsSize; i++) 
            freq[nums[i]]++;

        for (int i = 50; i >= 0; i--) {
            if (freq[i] == 1)
                return i;
        }
        return -1;
    }

    int left = -1;
    int right = -1;
    for (int i = 0; i < numsSize; i++) {
        freq[nums[i]]++;
        if (i == 0) 
            left = nums[i];
        else if (i == numsSize - 1)
            right = nums[i];
    }

    if (freq[left] > 1 && freq[right] > 1)
        return -1;

    else if (freq[left] == 1 && freq[right] == 1)
        return max(left, right);

    else if (freq[left] > 1)
        return right;
    
    else
        return left;
}
