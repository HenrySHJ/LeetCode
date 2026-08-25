# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

int minCut(char* s) {
    int n = strlen(s);
    if (n <= 1) 
        return 0;

    // Initialize palindrome table
    bool** isPalin = (bool**)malloc(n * sizeof(bool*));
    for (int i = 0; i < n; i++) {
        isPalin[i] = (bool*)calloc(n, sizeof(bool));
    }

    // Build palindrome table
    for (int len = 1; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (s[i] == s[j]) {
                if (len <= 2 || isPalin[i + 1][j - 1]) 
                    isPalin[i][j] = true;
            }
        }
    }

    // Build dp table
    int* dp = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        // Palindrome -> no cutting
        if (isPalin[0][i]) 
            dp[i] = 0; 
        
        // Executing cutting
        else {
            dp[i] = i; 
            for (int j = 0; j < i; j++) {
                if (isPalin[j + 1][i]) 
                    dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }

    int result = dp[n - 1];

    for (int i = 0; i < n; i++) 
        free(isPalin[i]);
    free(isPalin);
    free(dp);

    return result;
}