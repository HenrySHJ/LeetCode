# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int numDistinct(char* s, char* t) {
    int lenS = strlen(s);
    int lenT = strlen(t);

    unsigned long long dp[lenT + 1];

    for (int j = 0; j <= lenT; j++)
        dp[j] = 0;

    dp[0] = 1;

    for (int i = 1; i <= lenS; i++) {
        for (int j = lenT; j >= 1; j--) {
            if (s[i - 1] == t[j - 1]) {
                dp[j] += dp[j - 1];
            }
        }
    }

    return (int)dp[lenT];
}