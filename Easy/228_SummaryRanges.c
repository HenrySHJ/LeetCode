# include <stdio.h>
# include <stdlib.h>
# include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int capacity = 2;
char** ans;

char** summaryRanges(int* nums, int numsSize, int* returnSize) {
    ans = (char**)malloc(capacity * sizeof(char*));

    int index = 0;
    for (int i = 0; i < numsSize; i++) {
        int begin = nums[i];
        while (i < numsSize - 1 && nums[i] + 1 == nums[i + 1])
            i++;
        
        if (begin != nums[i]) {
            ans[index] = (char*)malloc(200 * sizeof(char));
            sprintf(ans[index], "%d->%d", begin, nums[i]);
            index++;
        }
        else {
            ans[index] = (char*)malloc(200 * sizeof(char));
            sprintf(ans[index], "%d", begin);
            index++;
        }

        if (index >= capacity) {
            capacity *= 2;
            ans = (char**)realloc(ans, capacity * sizeof(char*));
        }
    }    
    *returnSize = index;
    return ans;
}