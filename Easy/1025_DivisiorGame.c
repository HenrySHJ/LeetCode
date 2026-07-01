# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

bool divisorGame(int n) {
    // Initialize dp
    bool* dp = (bool*)calloc((n + 1), sizeof(bool));
    
    // set base case
    dp[0] = false;
    dp[1] = false;
    
    // fill dp table
    for (int i = 2; i < n + 1; i++) {
        for (int j = 1; j < i; j++) {
            if (i % j == 0) {
                if (dp[i - j] == false)
                    dp[i] = true;
                    break;
            }
        }
    }

    bool ans = dp[n];
    free(dp);
    return ans;
}