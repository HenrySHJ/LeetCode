#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numDecodings(char* s) {
    int len = strlen(s);
    if (len == 0 || s[0] == '0') return 0;

    // dp[i] : ways in range 0 ~ i - 1
    int* dp = (int*)calloc(len + 1, sizeof(int));
    
    // base case setting
    dp[0] = 1; 
    dp[1] = 1; 

    // filling dp table
    for (int i = 2; i <= len; i++) {
        // Case for one digit numbers
        int oneDigit = s[i - 1] - '0';
        if (oneDigit >= 1 && oneDigit <= 9) 
            dp[i] += dp[i - 1];

        // Case for two digit numbers
        int twoDigits = (s[i - 2] - '0') * 10 + oneDigit;
        if (twoDigits >= 10 && twoDigits <= 26) 
            dp[i] += dp[i - 2];
    }

    int ans = dp[len];
    free(dp);
    return ans;
}