# include <stdio.h>
# include <stdlib.h>
# define MOD 1000000007

int checkRecord(int n) {
    // dp[i][j][k] : Day i, Consecutive late : j, absent : k
    int dp[n + 1][3][2]; 

    // Base Case
    dp[1][0][0] = 1;
    dp[1][0][1] = 1;
    dp[1][1][0] = 1;
    dp[1][1][1] = 0;
    dp[1][2][0] = 0;
    dp[1][2][1] = 0;

    // Filling dp table
    for (int i = 2; i < n + 1; i++) {
        // Present
        dp[i][0][0] = (((dp[i - 1][0][0] + dp[i - 1][1][0]) % MOD) + dp[i - 1][2][0]) % MOD;
        dp[i][0][1] = (((dp[i - 1][0][1] + dp[i - 1][1][1]) % MOD) + dp[i - 1][2][1]) % MOD;
        
        // Late
        dp[i][1][0] = dp[i - 1][0][0];
        dp[i][1][1] = dp[i - 1][0][1];
        dp[i][2][0] = dp[i - 1][1][0];
        dp[i][2][1] = dp[i - 1][1][1];

        // Absent
        dp[i][0][1] = ((dp[i][0][1] + dp[i - 1][0][0]) % MOD + (dp[i - 1][1][0] + dp[i - 1][2][0]) % MOD) % MOD;
    }

    // Set Answer
    int ans = 0;
    for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 2; k++) {
            ans = (ans + dp[n][j][k]) % MOD;
        }
    }

    return ans;
}