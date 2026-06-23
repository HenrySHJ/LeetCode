# include <stdio.h>

int searchInsert(int* nums, int numsSize, int target) {
    int start = 0;
    int end = numsSize - 1;
    int mid = (start + end) / 2;

    // Start Binary Search
    while (start <= end) {
        mid = start + (end - start) / 2;
        
        if (nums[mid] == target) 
            return mid;
        else if (nums[mid] < target) 
            start = mid + 1;
        else
            end = mid - 1;
    }

    // Finding Insert Position
    if (nums[mid] < target)
        return mid + 1;
    else
        return mid;
}