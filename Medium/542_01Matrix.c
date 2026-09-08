# include <stdio.h>
# include <stdlib.h>

static inline int min(int a, int b) {
    return a < b ? a : b;
}

int** updateMatrix(int** mat, int matSize, int* matColSize, int* returnSize, int** returnColumnSizes) {
    int m = matSize;
    int n = matColSize[0];
    int INF = m + n; 

    int** ans = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) 
        ans[i] = (int*)malloc(n * sizeof(int));

    *returnSize = m;
    *returnColumnSizes = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) 
        (*returnColumnSizes)[i] = n;

    // First pass
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 0) 
                ans[i][j] = 0;
            else {
                ans[i][j] = INF;
                if (i > 0) 
                    ans[i][j] = min(ans[i][j], ans[i - 1][j] + 1);
                if (j > 0) 
                    ans[i][j] = min(ans[i][j], ans[i][j - 1] + 1);
            }
        }
    }

    // Second pass
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (i < m - 1) 
                ans[i][j] = min(ans[i][j], ans[i + 1][j] + 1);
            if (j < n - 1) 
                ans[i][j] = min(ans[i][j], ans[i][j + 1] + 1);
        }
    }

    return ans;
}
