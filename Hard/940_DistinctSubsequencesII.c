# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# define MOD 1000000007

int distinctSubseqII(char* s) {
    int n = strlen(s);

    // Initialize frequency array
    int last[26];
    for (int i = 0; i < 26; i++) 
        last[i] = -1;

    int dp[n + 1];
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        int x = s[i] - 'a';
        dp[i + 1] = (dp[i] * 2) % MOD;

        if (last[x] >= 0)
            dp[i + 1] -= dp[last[x]];

        dp[i + 1] %= MOD;
        last[x] = i;
    }

    // Erase Empty subsequence case
    dp[n]--;
    if (dp[n] < 0)
        dp[n] += MOD;

    return dp[n];
}