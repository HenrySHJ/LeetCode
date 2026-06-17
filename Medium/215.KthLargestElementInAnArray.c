# include <stdio.h>
# include <stdlib.h>

int findKthLargest(int* nums, int numsSize, int k) {
    int count[20001] = {};

    for (int i = 0; i < numsSize; i++)
        count[10000 + nums[i]]++;
    
    int cur = 0;
    for (int i = 20000; i >= -20000; i--) {
        cur = cur + count[i];
        if (cur >= k) return (i - 10000);
    }
    return 0;
}