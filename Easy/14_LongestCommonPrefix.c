# include <stdio.h>
# include <string.h>
# include <stdbool.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 1) {
        return strs[0];
    }

    int idx = 0;
    bool flag = false;
    for (idx = 0; ; idx++) {
        char c = strs[0][idx];
        for (int i = 1; i < strsSize; i++) {
            if (strs[i][idx] == '\0' || strs[i][idx] != c) {
                flag = true;
                break;
            }
        }

        if (flag) break;
    }

    char* ans = (char*)malloc((idx +1) * sizeof(char));
    for (int i = 0; i <= idx; i++) 
        ans[i] = strs[0][i];
    ans[idx] = '\0';
    
    return ans;
}