# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>

bool isMatch(char* s, char* p) {
    int len1 = strlen(s);
    int len2 = strlen(p);

    // dp[i][j] : checking s[0:i], p[0:j]
    bool** dp = (bool**)calloc(len1 + 1, sizeof(bool*));
    for (int i = 0; i < len1 + 1; i++) 
        dp[i] = (bool*)calloc(len2 + 1, sizeof(bool));

    // Setting base case
    dp[0][0] = true;
    for (int j = 1; j < len2 + 1; j++) {
        if (p[j - 1] == '*')
            dp[0][j] = dp[0][j - 2];
    }

    // Filling dp table
    for (int i = 1; i < len1 + 1; i++) {
        for (int j = 1; j < len2 + 1; j++) {
            // same character or '.' covers character
            if (p[j - 1] == s[i - 1] || p[j - 1] == '.')
                dp[i][j] = dp[i - 1][j - 1];
            // Checking if '*' is valid
            else if (p[j - 1] == '*') {
                dp[i][j] = dp[i][j - 2];
                if (p[j - 2]  == s[i - 1] || p[j - 2] == '.')
                    dp[i][j] = dp[i][j] | dp[i - 1][j];
            }
        }
    }
    bool ans = dp[len1][len2];
    for (int i = 0; i < len1 + 1; i++) 
        free(dp[i]);
    free(dp);
    return ans;
}

        

