# include <stdio.h>
# include <stdlib.h>

int max(int a, int b) {
    return (a < b) ? b : a;
}

int* dp;

int calJump(int* arr, int arrSize, int idx, int d) {
    // Memoization
    if (dp[idx] != -1)
        return dp[idx];

    int max_val = 1; 

    for (int j = 1; j <= d; j++) {
        int next_idx = idx - j;
        if (next_idx < 0) 
            break;

        if (arr[next_idx] >= arr[idx]) 
            break;

        max_val = max(max_val, calJump(arr, arrSize, next_idx, d) + 1);
    }

    for (int j = 1; j <= d; j++) {
        int next_idx = idx + j;
        if (next_idx >= arrSize) 
            break;

        if (arr[next_idx] >= arr[idx]) 
            break;

        max_val = max(max_val, calJump(arr, arrSize, next_idx, d) + 1);
    }

    dp[idx] = max_val;
    return dp[idx];
}

int maxJumps(int* arr, int arrSize, int d) {
    dp = (int*)malloc(arrSize * sizeof(int));
    for (int i = 0; i < arrSize; i++) 
        dp[i] = -1;
    
    int ans = 1;

    for (int i = 0; i < arrSize; i++) {
        ans = max(ans, calJump(arr, arrSize, i, d));
    }

    free(dp);
    return ans;
}