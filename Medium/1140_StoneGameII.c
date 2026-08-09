# include <stdio.h>
# include <stdlib.h>

int max(int a, int b) {
    if (a < b) return b;
    else return a;
}
int** dp;
int* suffix;

int solve(int i, int M, int n) {
    if (i + 2 * M >= n)
        return suffix[i];

    if (dp[i][M] != -1)
        return dp[i][M];

    int ans = 0;
    for (int X = 1; X <= 2 * M; X++) {
        int cur_stone = suffix[i] - solve(i + X, max(M, X), n);
        ans = max(ans, cur_stone);
    }

    dp[i][M] = ans;
    return ans;
}

int stoneGameII(int* piles, int pilesSize) {
    int n = pilesSize;

    // Initialize dp table
    dp = (int**)malloc((n + 1) * sizeof(int*));
    for (int i = 0; i < n + 1; i++)
        dp[i] = (int*)malloc((n + 1) * sizeof(int));

    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < n + 1; j++)
            dp[i][j] = -1;
    }

    // Initialize suffix table
    suffix = (int*)malloc((n + 1) * sizeof(int));
    suffix[n] = 0;
    for (int i = n - 1; i >= 0; i--) 
        suffix[i] = piles[i] + suffix[i + 1];

    int ans = solve(0, 1, n);

    // Free memory
    free(suffix);
    for (int i = 0; i < n + 1; i++)
        free(dp[i]);
    free(dp);

    return ans;
}
