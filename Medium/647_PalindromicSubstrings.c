# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>

int countSubstrings(char* s) {
    int n = strlen(s);
    int ans = n;

    bool dp[n][n];
    for (int i = 0; i < n; i++) {
        if (i >= 1)
            dp[i][i - 1] = true;
        dp[i][i] = true;
        for (int j = i + 1; j < n; j++) 
            dp[i][j] = false;
    }  

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i < n + 1 - len; i++) {
            int j = i + len - 1;

            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                ans++;
            }
        }
    }

    return ans;
}