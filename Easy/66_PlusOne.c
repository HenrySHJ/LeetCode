# include <stdio.h>
# include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    for (int i = digitsSize - 1; i >= 0; i--) {
        if (digits[i] != 9) {
            digits[i]++;
            int* ans = (int*)malloc(digitsSize * sizeof(int));
            *returnSize = digitsSize;

            for (int i = 0; i < digitsSize; i++)
                ans[i] = digits[i];
            return ans;
        }
        digits[i] = 0;
    }

    *returnSize = digitsSize + 1;
    int* ans = (int*)malloc((*returnSize) * sizeof(int));
    ans[0] = 1;
    for (int i = 1; i < *returnSize; i++) 
        ans[i] = 0;
    return ans;
}