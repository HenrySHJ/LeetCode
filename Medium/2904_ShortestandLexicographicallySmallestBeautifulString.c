# include <stdio.h>
# include <stdlib.h>
# include <string.h>

char* shortestBeautifulSubstring(char* s, int k) {
    int n = strlen(s);
    int l = 0;
    int count = 0;
    int len = n + 1;
    int ans_l = -1;

    for (int r = 0; r < n; r++) {
        if (s[r] == '1') {
            count++;
        }

        while (count == k) {
            while (s[l] == '0') 
                l++;

            if (r - l + 1 < len) {
                len = r - l + 1;
                ans_l = l;
            } 

            else if (r - l + 1 == len) {
                if (strncmp(s + l, s + ans_l, r - l + 1) < 0) {
                    ans_l = l;
                }
            }

            if (s[l] == '1') 
                count--;
            l++;
        }
    }

    if (ans_l == -1) {
        char* empty = (char*)malloc(1 * sizeof(char));
        empty[0] = '\0';
        return empty;
    }

    char* ans = (char*)malloc((len + 1) * sizeof(char));
    strncpy(ans, s + ans_l, len);
    ans[len] = '\0';

    return ans;
}