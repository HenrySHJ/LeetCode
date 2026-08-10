# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

bool winnerSquareGame(int n) {
    bool dp[n + 1];
    for (int i = 0; i < n + 1; i++)
        dp[i] = false;

    for (int i = 0; i < n; i++) {
        if (dp[i])
            continue;

        for (int k = 1; i + k * k <= n; k++)
            dp[i + k * k] = true;
    }

    return dp[n];
}