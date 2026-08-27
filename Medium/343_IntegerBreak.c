# include <stdio.h>
# include <stdlib.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int memo[58];

int solve(int n) {
    if (memo[n] != -1)
        return memo[n];

    int ans = 0;
    for (int i = 1; i <= n - 1; i++) 
        ans = max(ans, i * max(n - i, solve(n - i)));
    
    return memo[n] = ans;
}

int integerBreak(int n) {
    for (int i = 0; i <= n; i++)
        memo[i] = -1;
    memo[1] = 1;
    return solve(n);
}

