# include <stdio.h>
# include <stdlib.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int getMoneyAmount(int n) {
    int dp[n + 2][n + 2];
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= n + 1; j++) 
            dp[i][j] = 0;
    }


    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            int min_ans = INT_MAX;

            for (int k = i; k <= j; k++) {
                int cost = k + max(dp[i][k - 1], dp[k + 1][j]);
                min_ans = min(min_ans, cost);
            }

            dp[i][j] = min_ans;
        }
    }

    return dp[1][n];
}