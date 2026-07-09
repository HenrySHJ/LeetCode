# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>

bool isInterleave(char* s1, char* s2, char* s3) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int len3 = strlen(s3);

    if (len3 != len1 + len2) return false;
    
    // dp[i][j] : s1[0 ~ i], s2[0 ~ j] used
    bool dp[len1 + 1][len2 + 1];
    dp[0][0] = true;

    // Filling dp table
    for (int i = 0; i < len1 + 1; i++) {
        for (int j = 0; j < len2 + 1; j++) {
            if (i == 0 && j == 0) continue;
            dp[i][j] = false;
            
            if (i > 0 && s3[i + j - 1] == s1[i - 1])
                dp[i][j] = dp[i][j] || dp[i - 1][j];
            if (j > 0 && s3[i + j - 1] == s2[j - 1])
                dp[i][j] = dp[i][j] || dp[i][j - 1];
        }
    }

    bool ans = dp[len1][len2];

    return ans;
}