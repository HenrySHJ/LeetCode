# include <stdio.h>
# include <stdlib.h>
# define MOD 1000000007

int knightDialer(int n) {
    if (n == 1) return 10;

    long long dp[10];
    for (int i = 0; i < 10; i++) 
        dp[i] = 1; 
    

    long long next_dp[10];

    for (int step = 2; step <= n; step++) {
        next_dp[0] = (dp[4] + dp[6]) % MOD;
        next_dp[1] = (dp[6] + dp[8]) % MOD;
        next_dp[2] = (dp[7] + dp[9]) % MOD;
        next_dp[3] = (dp[4] + dp[8]) % MOD;
        next_dp[4] = (dp[0] + dp[3] + dp[9]) % MOD;
        next_dp[5] = 0;
        next_dp[6] = (dp[0] + dp[1] + dp[7]) % MOD;
        next_dp[7] = (dp[2] + dp[6]) % MOD;
        next_dp[8] = (dp[1] + dp[3]) % MOD;
        next_dp[9] = (dp[2] + dp[4]) % MOD;

        for (int i = 0; i < 10; i++) 
            dp[i] = next_dp[i];
    }

    long long ans = 0;
    for (int i = 0; i < 10; i++) {
        ans = (ans + dp[i]) % MOD;
    }

    return (int)ans;
}