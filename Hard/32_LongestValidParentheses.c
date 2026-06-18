# include <stdio.h>
# include <stdlib.h>

int longestValidParentheses(char* s) {
    int n = strlen(s);
    int left = 0, right = 0, maxLen = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') 
            left++;
        else 
            right++;

        if (left == right) {
            if (left * 2 > maxLen) 
                maxLen = left * 2;
        } else if (right > left) {
            left = right = 0; 
        }
    }

    left = right = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '(') 
            left++;
        else 
            right++;

        if (left == right) {
            if (left * 2 > maxLen) 
                maxLen = left * 2;
        } else if (left > right) {
            left = right = 0;
        }
    }

    return maxLen;
}