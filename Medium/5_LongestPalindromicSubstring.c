# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>

char* longestPalindrome(char* s) {
    int length = strlen(s);
    if (length == 0) return "";

    // dp[i][j] : true if i ~ j is palindromic 
    bool** dp = (bool**)calloc(length, sizeof(bool*));

    int start = 0;
    int max_len = 1;

    // Base case : dp[i][i]
    for (int i = 0; i < length; i++) {
        dp[i] = (bool*)calloc(length, sizeof(bool));
        dp[i][i] = true;
    }
    for (int i = 0; i < length - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            start = i;
            max_len = 2;
        }
    }

    // Topological Order : 
    for (int len = 3; len <= length; len++) {
        for (int i = 0; i <= length - len; i++) {
            int j = i + len - 1; 

            // Updating dp
            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                // Update maximum length
                if (len > max_len) {
                    start = i;
                    max_len = len;
                }
            }
        }
    }

    // free memory
    for (int i = 0; i < length; i++) {
        free(dp[i]);
    }
    free(dp);

    // Setting answer
    char* ans = (char*)malloc((max_len + 1) * sizeof(char));
    for (int i = 0; i < max_len; i++) {
        ans[i] = s[start + i]; 
    }
    ans[max_len] = '\0';
    return ans;
}