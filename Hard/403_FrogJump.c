# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

bool canCross(int* stones, int stonesSize) {
    // Exceptional Case
    if (stones[1] != 1) return false;

    // Initialize dp 
    // dp[i][j] : can arrive stone i, last jump was k unit
    bool** dp = (bool**)calloc(stonesSize, sizeof(bool*));
    for (int i = 0; i < stonesSize; i++) 
        dp[i] = (bool*)calloc(stonesSize + 1, sizeof(bool));

    // Set base case
    dp[1][1] = true;

    // Topological Order
    for (int i = 2; i < stonesSize; i++) {
        for (int j = 1; j < i; j++) {
            int diff = stones[i] - stones[j]; 

            if (diff <= 0 || diff >= stonesSize) 
                continue;

            if (dp[j][diff - 1] || dp[j][diff] || dp[j][diff + 1]) {
                dp[i][diff] = true;
            }
        }
    }

    // find answer
    bool ans = false;
    for (int j = 0; j < stonesSize; j++) {
        if (dp[stonesSize - 1][j]) {
            ans = true;
            break;
        }
    }

    // free memory
    for (int i = 0; i < stonesSize; i++)
        free(dp[i]);
    free(dp);

    return ans;
}