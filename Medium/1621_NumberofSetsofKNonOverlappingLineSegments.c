# include <stdio.h>
# include <stdlib.h>
# define MOD 1000000007

int numberOfSets(int n, int k) {
    int* dp = malloc(n * sizeof(int));
    
    int* prefix = calloc(n + 1, sizeof(int));
    for (int j = 0; j < n; j++) {
        dp[j] = 1;
        prefix[j + 1] = (prefix[j] + dp[j]) % MOD;
    }

    for (int i = 1; i <= k; i++) {
        dp[0] = 0;

        for (int j = 1; j < n; j++) 
            dp[j] = (dp[j - 1] + prefix[j]) % MOD;
        
        for (int j = 0; j < n; j++) 
            prefix[j + 1] = (prefix[j] + dp[j]) % MOD;
    }

    int answer = dp[n - 1];

    free(dp);
    free(prefix);

    return answer;
}
