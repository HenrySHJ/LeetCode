# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int reverseDegree(char* s) {
    int n = strlen(s);
    int ans = 0;

    for (int i = 0; i < n; i++) {
        ans += (26 - (s[i] - 'a')) * (i + 1);
    }

    return ans;
}
