# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int lengthOfLastWord(char* s) {
    int len = strlen(s);
    int ans = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (s[i] != ' ')
            ans++;
        else {
            if (ans == 0)
                continue;
            else
                break;
        } 
    }
    return ans;
}