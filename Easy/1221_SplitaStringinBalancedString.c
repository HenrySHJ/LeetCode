# include <stdio.h>
# include <stdlib.h>

int balancedStringSplit(char* s) {
    int n = strlen(s);
    int count = 0;
    int ans = 0;
    
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L')
            count++;
        else
            count--;

        if (count == 0)
            ans++;
    }

    return ans;
}