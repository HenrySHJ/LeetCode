# include <stdio.h>
# include <stdlib.h>
# include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// Dynamic string array for answer
char** ans;
int capacity;
int count;
int size;

int open;
int closed;

void dfs(char* s, int idx) {
    // Adding Valid Parentheses to Answer
    if (idx == size) {
        ans[count] = (char*)malloc((size + 1) * sizeof(char));
        strcpy(ans[count], s);
        count++;

        // Reallocating dynamic array
        if (count >= capacity) {
            capacity *= 2;
            ans = (char**)realloc(ans, capacity * sizeof(char*));
        }
        
        return;
    }

    // Can add ')' when array has more '('
    if (open > closed) {
        s[idx] = ')';
        closed++;

        dfs(s, idx + 1);
        closed--;
    }
    // Can add '(' when array has less than half of '('
    if (open < size / 2) {
        s[idx] = '(';
        open++;

        dfs(s, idx + 1);
        open--;
    }
}

char** generateParenthesis(int n, int* returnSize) {
    capacity = 2;
    count = 0;
    size = n * 2;
    ans = (char**)malloc(capacity * sizeof(char*));
    
    open = 0;
    closed = 0;

    char* string = (char*)malloc((size + 1) * sizeof(char));
    string[size] = '\0';
    dfs(string, 0);
    free(string);

    *returnSize = count;
    return ans;
}