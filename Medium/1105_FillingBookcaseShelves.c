# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int minHeightShelves(int** books, int booksSize, int* booksColSize, int shelfWidth) {
    int n = booksSize;

    // Initialize dp table
    int dp[n + 1];
    for (int i = 2; i < n + 1; i++)
        dp[i] = INT_MAX;

    // Set base case
    dp[0] = 0;
    dp[1] = books[0][1];

    // Tabulation
    for (int i = 1; i < n + 1; i++) {
        // New Shelf
        int remWidth = shelfWidth - books[i - 1][0];
        int maxH = books[i - 1][1];
        dp[i] = dp[i - 1] + maxH;

        int j = i - 1;
        // Combine books
        while (j > 0 && remWidth - books[j - 1][0] >= 0) {
            remWidth -= books[j - 1][0];
            maxH = max(maxH, books[j - 1][1]);
            dp[i] = min(dp[i], dp[j - 1] + maxH);
            j--;
        }
        
    }

    return dp[n];
}