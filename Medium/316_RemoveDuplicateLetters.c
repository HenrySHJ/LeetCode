# include <stdio.h>
# include <string.h>
# include <stdbool.h>

char* removeDuplicateLetters(char* s) {
    int n = strlen(s);

    int* lastIndex = (int*)calloc(26, sizeof(int));
    bool* check = (bool*)calloc(26, sizeof(bool));
    
    for (int i = 0; i < n; i++) 
        lastIndex[s[i] - 'a'] = i;
    
    char* stack = (char*)malloc((n + 1) * sizeof(char));
    int top = 0;
    for (int i = 0; i < n; i++) {
        int cur = s[i] - 'a';
        if (check[cur])
            continue;

        while (top > 0 && stack[top - 1] > s[i] && lastIndex[stack[top - 1] - 'a'] > i) {
            check[stack[top - 1] - 'a'] = false;
            top--;
        }

        // stack push
        stack[top++] = s[i];
        check[cur] = true;
    }

    char* ans = (char*)malloc((top + 1) * sizeof(char));
    for (int i = 0; i < top; i++) {
        ans[i] = stack[i];
    }
    ans[top] = '\0';
    free(stack);

    return ans;
}