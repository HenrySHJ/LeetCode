#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int* diffWaysToCompute(char* expression, int* returnSize) {
    int m = strlen(expression);
    int nums[20];
    char ops[20];
    int n = 0; // num count

    // Parsing into numbers and operations
    for (int i = 0; i < m; ) {
        if (isdigit(expression[i])) {
            int val = 0;
            while (i < m && isdigit(expression[i])) {
                val = val * 10 + (expression[i] - '0');
                i++;
            }
            nums[n++] = val;
        } 
        else {
            ops[n - 1] = expression[i];
            i++;
        }
    }

    // Initializing dp table
    int capacity[n][n];
    int size[n][n];
    int*** dp = (int***)malloc(n * sizeof(int**));

    for (int i = 0; i < n; i++) {
        dp[i] = (int**)malloc(n * sizeof(int*));
        for (int j = 0; j < n; j++) {
            capacity[i][j] = 2;
            size[i][j] = 0;
            dp[i][j] = (int*)malloc(capacity[i][j] * sizeof(int));
        }
    }

    // Base Case: length 1
    for (int i = 0; i < n; i++) {
        dp[i][i][0] = nums[i];
        size[i][i] = 1;
    }

    // Topological order : Interval dp (length 2 ~ n)
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;

            // k : operator index
            for (int k = i; k < j; k++) {
                char op = ops[k];

                for (int left = 0; left < size[i][k]; left++) {
                    for (int right = 0; right < size[k + 1][j]; right++) {
                        
                        // Reallocating dynmaic array
                        if (size[i][j] >= capacity[i][j]) {
                            capacity[i][j] *= 2;
                            dp[i][j] = (int*)realloc(dp[i][j], capacity[i][j] * sizeof(int));
                        }

                        // Operation
                        int leftVal = dp[i][k][left];
                        int rightVal = dp[k + 1][j][right];

                        if (op == '+') 
                            dp[i][j][size[i][j]++] = leftVal + rightVal;
                        else if (op == '-') 
                            dp[i][j][size[i][j]++] = leftVal - rightVal;
                        else if (op == '*') 
                            dp[i][j][size[i][j]++] = leftVal * rightVal;
                    }
                }
            }
        }
    }

    *returnSize = size[0][n - 1];
    int* ans = dp[0][n - 1];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == n - 1) continue;
            free(dp[i][j]);
        }
        free(dp[i]);
    }
    free(dp);

    return ans;
}
