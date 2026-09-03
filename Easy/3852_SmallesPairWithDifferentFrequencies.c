# include <stdio.h>
# include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* minDistinctFreqPair(int* nums, int numsSize, int* returnSize) {
    int freq[101] = {0};
    for (int i = 0; i < numsSize; i++)
        freq[nums[i]]++;

    int* ans = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    int start = -1;
    for (int i = 1; i < 101; i++) {
        if (freq[i] > 0) {
            start = i;
            break;
        }
    }   

    if (start == -1) {
        ans[0] = -1;
        ans[1] = -1;
        return ans;
    }

    int end = -1;
    for (int i = start + 1; i < 101; i++) {
        if (freq[i] > 0 && (freq[i] != freq[start])) {
            end = i;
            break;
        }
    }

    if (end == -1) {
        ans[0] = -1;
        ans[1] = -1;
        return ans;
    }

    ans[0] = start;
    ans[1] = end;

    return ans;
}