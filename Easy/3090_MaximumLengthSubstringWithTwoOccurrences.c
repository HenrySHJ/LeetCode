# include <stdio.h>
# include <string.h>

int maximumLengthSubstring(char* s) {
    int n = strlen(s);
    int l = 0;
    int r = 0;
    int occur[26] = {0};
    int ans = 0;

    while (r < n) {
        if (occur[s[r] - 'a'] < 2) 
            occur[s[r++] - 'a']++;

        else 
            occur[s[l++] - 'a']--;

        if (ans < r - l)
            ans = r - l;
    }

    return ans;
}
