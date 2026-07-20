# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

int min(int a, int b) {
    return (a <= b) ? a : b;
}

int racecar(int target) {
    // Set dp table
    int* dp = (int*)malloc((target + 1) * sizeof(int));
    
    // Set base case
    dp[0] = 0;
    
    int r = 1;
    for (int i = 1; i <= target; i++) {
        dp[i] = INT_MAX;
        
        while ((1 << r) - 1 < i) 
            r++;
        
        int upper = (1 << r) - 1;
        
        // Only Acceleration
        if (i == upper) {
            dp[i] = r;
            continue;
        }
        
        // Stop after the target
        dp[i] = min(dp[i], r + 1 + dp[upper - i]);
        
        // Stop before the target
        int lower = (1 << (r - 1)) - 1;
        for (int j = 0; j < r - 1; j++) {
            int back_dist = (1 << j) - 1;
          
            int rem_dist = i - lower + back_dist;
            
            dp[i] = min(dp[i], (r - 1) + 1 + j + 1 + dp[rem_dist]);
        }
    }
    
    int result = dp[target];
    free(dp);
    
    return result;
}