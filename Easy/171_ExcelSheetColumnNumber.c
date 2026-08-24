# include <stdio.h>
# include <string.h>

int titleToNumber(char* columnTitle) {
    int n = strlen(columnTitle);
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int num = columnTitle[i] - 'A' + 1;
        ans = ans * 26 + num;
    }

    return ans;
}