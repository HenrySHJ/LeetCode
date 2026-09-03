# include <stdio.h>
# include <stdlib.h>

int compare(const void* a, const void* b) {
    int num1 = *(int*)a;
    int num2 = *(int*)b;
    return (num1 > num2) - (num1 < num2);
}

int max(int a, int b) {
    return a > b ? a : b;
}

int minPairSum(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), compare);

    int ans = 0;
    for (int i = 0; i < numsSize / 2; i++) 
        ans = max(ans, nums[i] + nums[numsSize - 1 - i]);
    
    return ans;
}