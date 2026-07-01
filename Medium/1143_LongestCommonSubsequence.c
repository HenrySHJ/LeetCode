#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b) {
    return (a >= b) ? a : b;
}

int longestCommonSubsequence(char* text1, char* text2) {
    int len1 = strlen(text1);
    int len2 = strlen(text2);

    int dp[len1 + 1][len2 + 1];
    for (int i = 0; i <= len1; i++)
        dp[i][0] = 0;
    for (int j = 0; j <= len2; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (text1[i - 1] == text2[j - 1]) 
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else 
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int ans = dp[len1][len2];
    return ans;
}