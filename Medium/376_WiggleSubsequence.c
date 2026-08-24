# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

int max(int a, int b) {
    return a < b ? b : a;
}

int max3(int a, int b, int c) {
    if (a < b && b < c)
        return c;
    else if (a < b)
        return b;
    else
        return a;
}

// Solution 1 : DP
int wiggleMaxLength(int* nums, int numsSize) {
    int n = numsSize;

    // Initialize dp table
    int dp[n][2];
    for (int i = 0; i < n; i++) {
        dp[i][0] = 1;
        dp[i][1] = 1;
    }

    // Set base case
    dp[0][0] = 1;
    dp[0][1] = 1;

    // Topological order
    int ans = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j])
                dp[i][0] = max(dp[i][0], dp[j][1] + 1);
            else if (nums[i] < nums[j])
                dp[i][1] = max(dp[i][1], dp[j][0] + 1);
        }
        ans = max(ans, max(dp[i][0], dp[i][1]));
    }

    return ans;
}

// Solution 2 : Greedy
int wiggleMaxLength(int* nums, int numsSize) {
    if (numsSize < 2) return numsSize;

    int up = 1;
    int down = 1;

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > nums[i - 1]) {
            up = down + 1;
        } else if (nums[i] < nums[i - 1]) {
            down = up + 1;
        }
    }

    return (up > down) ? up : down;
}