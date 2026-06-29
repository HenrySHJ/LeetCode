# include <stdio.h>
# include <stdlib.h>

int* countBits(int n, int* returnSize) {
    *returnSize = n + 1;
    int* ans = (int*)calloc(n + 1, sizeof(int));

    // Base Setting
    ans[0] = 0;
    if (n >= 1) ans[1] = 1;

    // Topological Order
    for (int i = 1; i < (n / 2) + 1; i++) {
        // Relation
        ans[i * 2] = ans[i];
        if (i * 2 + 1 <= n)
            ans[(i * 2) + 1] = ans[i] + 1; 
    }
    return ans;
}