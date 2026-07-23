# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>

char* smallestSubsequence(char* s) {
    int n = strlen(s);
    int* lastIndex = (int*)calloc(26, sizeof(int));
    for (int i = 0; i < n; i++) 
        lastIndex[s[i] - 'a'] = i;
    
    bool* check = (bool*)calloc(26, sizeof(bool));
    char* stack = (char*)malloc((n + 1) * sizeof(char));
    int top = 0;

    for (int i = 0; i < n; i++) {
        int cur = s[i] - 'a';

        if (check[cur])
            continue;

        while (top > 0 && stack[top] - 1 > s[i] && lastIndex[stack[top - 1] - 'a'] > i) {
            check[stack[top - 1] - 'a'] = false;
            top--;
        }

        check[cur] = true;
        stack[top++] = s[i];
    }
    
    char* ans = (char*)malloc((top + 1) * sizeof(char));

    for (int i = 0; i < top; i++) 
        ans[i] = stack[i];
    ans[top] = '\0';

    free(stack);
    free(check);
    free(lastIndex);

    return ans;
}