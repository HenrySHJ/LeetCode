#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int memo[100][100][100];

int max(int a, int b) {
    return (a > b) ? a : b;
}

int solve(int* boxes, int i, int j, int k) {
    if (i > j) return 0;
    
    // Reuse by Memoization
    if (memo[i][j][k] != 0) 
        return memo[i][j][k];

    // Optimizing by adding same color box on left
    int oi = i;
    int ok = k;
    while (i + 1 <= j && boxes[i] == boxes[i + 1]) {
        i++;
        k++;
    }

    // Using continuous k + 1 boxes first
    int res = (k + 1) * (k + 1) + solve(boxes, i + 1, j, 0);

    // Using i + 1 ~ m - 1 boxes first
    for (int m = i + 1; m <= j; m++) {
        if (boxes[m] == boxes[i] && boxes[m] != boxes[m - 1]) {
            int total = solve(boxes, i + 1, m - 1, 0) + solve(boxes, m, j, k + 1);
            res = max(res, total);
        }
    }

    memo[oi][j][ok] = res;
    return res;
}

int removeBoxes(int* boxes, int boxesSize) {
    // Reset dp table
    memset(memo, 0, sizeof(memo));
    
    return solve(boxes, 0, boxesSize - 1, 0);
}