# include <stdio.h>
# include <string.h>

int max(int a, int b) {
    return a > b ? a : b;
}
int maxScore(char* s) {
    int n = strlen(s);
    int prefix[n + 2];
    int suffix[n + 2];
    prefix[0] = 0;
    suffix[n + 1] = 0;

    for (int i = 0; i < n; i++) 
        prefix[i + 1] = prefix[i] + (s[i] == '0' ? 1 : 0);
    for (int i = n; i >= 1; i--) 
        suffix[i] = suffix[i + 1] + s[i - 1] - '0';
    
    int ans = 0;
    for (int i = 1; i < n; i++) 
        ans = max(ans, prefix[i] + suffix[i + 1]);

    return ans;
}
