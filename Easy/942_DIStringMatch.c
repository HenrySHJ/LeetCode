# include <stdio.h>
# include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* diStringMatch(char* s, int* returnSize) {
    int n = strlen(s);
    int* ans = (int*)malloc((n + 1) * sizeof(int));
    
    int l = 0; int r = n;
    for (int i = 0; i < n + 1; i++) {
        if (s[i] == 'I') 
            ans[i] = l++;
        else
            ans[i] = r--;
    }
    *returnSize = n + 1;
    return ans;
}