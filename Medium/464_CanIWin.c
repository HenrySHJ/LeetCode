# include <stdio.h>
# include <stdbool.h>
# include <string.h>

signed char dp[1 << 21];

bool dfs(int maxChoosable, int desiredTotal, int state, int currentSum) {
    if (dp[state] != 0) 
        return dp[state] == 1;

    for (int i = 1; i <= maxChoosable; i++) {
        int bit = (1 << i);

        // Checking if number is unused
        if ((state & bit) == 0) {
            // Win : Can make a desiredTotal
            if (currentSum + i >= desiredTotal) {
                dp[state] = 1;
                return true;
            }

            // Win : If next player can't make winning movement
            if (!dfs(maxChoosable, desiredTotal, state | bit, currentSum + i)) {
                dp[state] = 1;
                return true;
            }
        }
    }

    // Lose : Except winning case
    dp[state] = 2;
    return false;
}

bool canIWin(int maxChoosableInteger, int desiredTotal) {
    // Exception case 1 : Win by starting
    if (maxChoosableInteger >= desiredTotal) 
        return true;

    // Exception case 2 : Can't make desiredTotal
    int sum = (maxChoosableInteger * (maxChoosableInteger + 1)) / 2;
    if (sum < desiredTotal) return false;

    // Initialize dp table
    memset(dp, 0, sizeof(dp));

    return dfs(maxChoosableInteger, desiredTotal, 0, 0);
}