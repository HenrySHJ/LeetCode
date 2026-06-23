# include <stdio.h>

int mySqrt(int x) {
    // Exception for 0 and 1
    if (x < 2) {
        return x;
    }
    
    // Setting minimum and maximum range
    int left = 1;
    int right = x / 2; 
    int ans = 0;
    
    // Binary Search
    while (left <= right) {
        int mid = left + (right - left) / 2; 
        
        if (mid == x / mid) {
            return mid;
        }
        else if (mid < x / mid) {
            ans = mid;     
            left = mid + 1;
        } 
        else {
            right = mid - 1;
        }
    }
    
    return ans;
}