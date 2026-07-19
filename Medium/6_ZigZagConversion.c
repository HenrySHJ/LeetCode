# include <stdio.h>
# include <string.h>

char* convert(char* s, int numRows) {
    int len = strlen(s);

    if (numRows == 1 || len <= numRows)
        return s;

    char* ans = (char*)malloc((len + 1) * sizeof(char));
    ans[len] = '\0';

    int idx = 0;
    int gap = numRows * 2 - 2;

    for (int i = 0; i < len; i += gap) 
        ans[idx++] = s[i];

    for (int r = 1; r < numRows - 1; r++) {
        ans[idx++] = s[r];
        for (int i = gap - r; i < len; i += gap) {
            ans[idx++] = s[i];

            if (i + r * 2 < len)
                ans[idx++] = s[i + r * 2];
        }
    }

    for (int i = numRows - 1; i < len; i += gap) 
        ans[idx++] = s[i];
    
    return ans;
}