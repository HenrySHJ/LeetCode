#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int longestPalindrome(char* s) {
    int counts[128] = {0};
    int len = strlen(s);

    // Frequency for each character
    for (int i = 0; i < len; i++) {
        counts[(int)s[i]]++;
    }

    int ans = 0;
    bool odd = false;

    for (int i = 0; i < 128; i++) {
        int count = counts[i];
        
        ans += (count / 2) * 2;

        // Special count for odd
        if (count % 2 == 1) 
            odd = true;
    }

    if (odd) 
        ans++;
    
    return ans;
}