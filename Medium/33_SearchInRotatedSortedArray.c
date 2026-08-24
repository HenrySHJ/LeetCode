# include <stdio.h>
# include <stdlib.h>

int binary_search(int* nums, int left, int right, int target) {
    if (left > right)
        return -1;

    int mid = left + (right - left) / 2;

    if (nums[mid] == target)
        return mid;

    if (nums[left] <= nums[mid]) {
        if (nums[left] <= target && target < nums[mid]) 
            return binary_search(nums, left, mid - 1, target);
        else 
            return binary_search(nums, mid + 1, right, target);
    }

    else {
        if (nums[mid] < target && target <= nums[right]) 
            return binary_search(nums, mid + 1, right, target);
        else 
            return binary_search(nums, left, mid - 1, target);
    }
}

int search(int* nums, int numsSize, int target) {
    return binary_search(nums, 0, numsSize - 1, target);
}
