# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int min(int a, int b, int c) {
    if (a < b && a < c)
        return a;
    else if (b < c)
        return b;
    else 
        return c;
}

int minDistance(char* word1, char* word2) {
    int m = strlen(word1);
    int n = strlen(word2);

    // Initialize dp table
    int dp[m + 1][n + 1];    

    // Setting base case
    for (int i = 0; i < m + 1; i++) 
        dp[i][0] = i;
    for (int j = 0; j < n + 1; j++)
        dp[0][j] = j;

    // Topological order
    for (int i = 1; i < m + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            if (word1[i - 1] == word2[j - 1]) 
                dp[i][j] = dp[i - 1][j - 1];
            else 
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
        }
    }

    return dp[m][n];
}