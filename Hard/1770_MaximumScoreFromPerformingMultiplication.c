# include <stdio.h>
# include <stdlib.h>

int* num;
int* mul;
int n;
int m;
int memo[1000][1000];

int max(int a, int b) {
    return a > b ? a : b;
}

int dfs(int i, int l) {
    if (i == m)
        return 0;

    if (memo[i][l] != -1)
        return memo[i][l];
    return memo[i][l] = max(mul[i] * num[l] + dfs(i + 1, l + 1), mul[i] * num[n - 1 - (i - l)] + dfs(i + 1, l));
}

int maximumScore(int* nums, int numsSize, int* multipliers, int multipliersSize) {
    n = numsSize;
    m = multipliersSize;

    num = nums;
    mul = multipliers;

    memset(memo, -1, sizeof(memo));
    return dfs(0, 0);
}
