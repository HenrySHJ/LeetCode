# include <stdio.h>
# include <stdlib.h>
# include <string.h>

char* largestOddNumber(char* num) {
    int n = strlen(num);
    char* ans = (char*)malloc((n + 1) * sizeof(char));

    int r = -1;
    for (int i = n - 1; i >= 0; i--) {
        if ((num[i] - '0') % 2 != 0) {
            r = i;
            break;
        }
    }

    if (r == -1)
        return "";
    for (int i = 0; i <= r; i++) {
        ans[i] = num[i];
    }
    ans[r + 1] = '\0';
    return ans;
}