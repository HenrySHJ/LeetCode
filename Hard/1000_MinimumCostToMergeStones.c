# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

int mergeStones(int* stones, int stonesSize, int k) {
    // Unable to merge piles
    if ((stonesSize - 1) % (k - 1))
        return -1;

    // dp[i][j] : Minimum cost when merged index i to j
    int dp[stonesSize][stonesSize];

    // Prefix Sum
    int prefix[stonesSize + 1];
    prefix[0] = 0;
    for (int i = 0; i < stonesSize; i++)
        prefix[i + 1] = prefix[i] + stones[i];

    // Base Case
    for (int i = 0; i < stonesSize; i++)
        dp[i][i] = 0;

    // Topological order by increasing pile units
    for (int l = 2; l <= stonesSize; l++) {
        for (int i = 0; i + l <= stonesSize; i++) {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;

            for (int mid = i; mid < j; mid += k - 1)
                dp[i][j] = MIN(dp[i][j], dp[i][mid] + dp[mid + 1][j]);

            if ((j - i) % (k - 1) == 0) 
                dp[i][j] += prefix[j + 1] - prefix[i];
        }
    }

    return dp[0][stonesSize - 1];
}

