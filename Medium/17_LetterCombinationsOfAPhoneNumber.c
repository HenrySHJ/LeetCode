# include <stdio.h>
# include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

char** ans;
const char* phone[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
int capacity;
int count;
int length;
char* string;

void dfs(char* digits, int index) {
    // Adding answer
    if (index == length) {
        ans[count] = (char*)malloc((length + 1) * sizeof(char));
        ans[count][length] = '\0';
        strcpy(ans[count], string);
        count++; 

        // Reallocating dynamic array
        if (count >= capacity) {
            capacity *= 2;
            ans = (char**)realloc(ans, capacity * sizeof(char*));
        }   
        return;
    }

    int num = digits[index] - '0';
    int diallen = strlen(phone[num]);
    for (int i = 0; i < diallen; i++) {
        string[index] = phone[num][i];
        dfs(digits, index + 1);
    }
    
}

char** letterCombinations(char* digits, int* returnSize) {
    capacity = 2;
    ans = (char**)malloc(capacity * sizeof(char*));
    
    count = 0;
    length = strlen(digits);

    string = (char*)malloc((length + 1) * sizeof(char));
    string[length] = '\0';

    dfs(digits, 0);

    *returnSize = count;
    return ans;
}