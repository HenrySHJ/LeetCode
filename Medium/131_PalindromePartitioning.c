# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>

char*** ans;
int* colSizes;
int capacity;
int count;

// dp[i][j] : true if i ~ j is palindrome
void checkPalindrome(char* s, int size, bool** dp) {
    for (int len = 1; len <= size; len++) {
        for (int i = 0; i <= size - len; i++) {
            int j = i + len - 1;

            if (s[i] == s[j] && (len <= 2 || dp[i + 1][j - 1])) {
                dp[i][j] = true;
            }
        }
    }
}

void backtrack(char* s, int start, int size, bool** dp, char** currentPath, int pathSize) {
    if (start >= size) {
        // Increasing the capacity of dynamic array
        if (count >= capacity) {
            capacity *= 2;
            ans = (char***)realloc(ans, capacity * sizeof(char**));
            colSizes = (int*)realloc(colSizes, capacity * sizeof(int));
        }


        ans[count] = (char**)malloc(pathSize * sizeof(char*));
        for (int i = 0; i < pathSize; i++) 
            ans[count][i] = strdup(currentPath[i]);

        colSizes[count] = pathSize;
        count++;
        return;
    }

    for (int i = start; i < size; i++) {
        if (dp[start][i]) {
            
            int len = i - start + 1;
            char* sub = (char*)malloc((len + 1) * sizeof(char));
            strncpy(sub, s + start, len);
            sub[len] = '\0';

            currentPath[pathSize] = sub;
            backtrack(s, i + 1, size, dp, currentPath, pathSize + 1);

            free(sub);
        }
    }
}

char*** partition(char* s, int* returnSize, int** returnColumnSizes) {
    int length = strlen(s);

    // dp[i][j] : true if i ~ j is palindrome
    bool** dp = (bool**)malloc(length * sizeof(bool*));
    for (int i = 0; i < length; i++) 
        dp[i] = (bool*)calloc(length, sizeof(bool));
    checkPalindrome(s, length, dp);

    // Initialize dynamic array
    capacity = 16;
    count = 0;
    ans = (char***)malloc(capacity * sizeof(char**));
    colSizes = (int*)malloc(capacity * sizeof(int));

    // Temporary path to remember
    char** currentPath = (char**)malloc(length * sizeof(char*));

    backtrack(s, 0, length, dp, currentPath, 0);

    *returnSize = count;
    *returnColumnSizes = colSizes;

    // Free Memory
    for (int i = 0; i < length; i++) 
        free(dp[i]);
    free(dp);
    free(currentPath);

    return ans;
}