# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int max(int a, int b) {
    return (a < b) ? b : a;
}

int characterReplacement(char* s, int k) {
    int n = strlen(s);
    int ans = 0;

    for (char c = 'A'; c <= 'Z'; c++) {
        int l = 0;
        int r = 0;
        int change = 0;

        while (r < n) {
            if (s[r] == c)
                r++;
            else if (change < k) {
                r++;
                change++;
            }
            else if (s[l] == c)
                l++;
            else {
                l++;
                change--;
            }
            ans = max(ans, r - l);
        } 
    }
    return ans;
}