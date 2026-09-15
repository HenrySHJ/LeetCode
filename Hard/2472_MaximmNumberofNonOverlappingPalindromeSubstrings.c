# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int max(int a, int b) {
    return a > b ? a : b;
}


// Solution 1 : DP
int maxPalindromes(char* s, int k) {
    int n = strlen(s);

    // Initialize Palindrome table
    bool isPalindrome[n][n];
    for (int i = 0; i < n; i++) {
        if (i > 0)
            isPalindrome[i][i - 1] = true;
        isPalindrome[i][i] = true;

        for (int j = i + 1; j < n; j++)
            isPalindrome[i][j] = false;
    }

    // Filling Palindrome table
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i < n - len + 1; i++) {
            int j = i + len - 1;

            if (s[i] == s[j])
                isPalindrome[i][j] = isPalindrome[i + 1][j - 1];
        }
    }

    // Initialize dp table
    int dp[n + 1];
    dp[0] = 0;

    // Tabulation
    for (int i = 1; i < n + 1; i++) {
        dp[i] = dp[i - 1];

        for (int j = 0; j <= i - k; j++) {
            if (isPalindrome[j][i - 1]) 
                dp[i] = max(dp[i], dp[j] + 1);            
        }
    }

    return dp[n];
}

// Solution 2 : Greedy
bool check(char* s, int l, int r) {
    while (l < r) {
        if (s[l++] != s[r--]) {
            return false;
        }
    }
    return true;
}

int maxPalindromes(char* s, int k) {
    int n = strlen(s);
    int ans = 0, start = 0;

    for (int r = k - 1; r < n; ++r) {
        int l = r - k + 1;
        if (l >= start && check(s, l, r)) {
            ans++;
            start = r + 1;
            continue;
        }

        l = r - k;
        if (l >= start && check(s, l, r)) {
            ans++;
            start = r + 1;
        }
    }

    return ans;
}
