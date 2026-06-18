# include <stdio.h>

int fib(int n) {
    int DP[n + 1] = {};

    DP[0] = 0;
    if (n >= 1) DP[1] = 1;

    for (int i = 2; i <= n; i++) 
        DP[i] = DP[i - 1] + DP[i - 2];
    
    return DP[n];
}