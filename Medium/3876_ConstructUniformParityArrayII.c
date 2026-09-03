# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

int min(int a, int b) {
    return a < b ? a : b;
}

bool uniformArray(int* nums1, int nums1Size) {
    int n = nums1Size;
    int min_odd = INT_MAX;
    int min_even = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (nums1[i] % 2 == 1) 
            min_odd = min(min_odd, nums1[i]);
        else
            min_even = min(min_even, nums1[i]);
    }

    if (min_odd == INT_MAX || min_even == INT_MAX)
        return true;

    int p = -1;
    if (min_odd < min_even)
        return true;
    else
        return false;

    
}