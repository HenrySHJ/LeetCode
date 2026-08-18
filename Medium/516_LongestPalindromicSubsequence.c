# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>

int max(int a, int b) {
    return (a < b) ? b : a;
}

int longestPalindromeSubseq(char* s) {
    int n = strlen(s);

    // Initializing dp table
    // dp[i][j] : max palindrome length of i ~ j
    int dp[n][n];
    for (int i = 0; i < n; i++) {
        if (i >= 1)
            dp[i][i - 1] = 0;
        dp[i][i] = 1;

        for (int j = i + 1; j < n; j++) 
            dp[i][j] = 0;
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;

            if (s[i] == s[j])
                dp[i][j] = dp[i + 1][j - 1] + 2;
            else 
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);    
        }
    }

    return dp[0][n - 1];
}