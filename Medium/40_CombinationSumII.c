# include <stdio.h>
# include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int capacity;
int** ans;
int count;

int* cur;
int size;
int** rcs;

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void dfs(int* candidates, int candidatesSize, int start, int target, int** returnColumnSizes) {
    // Reached target
    if (target == 0) {
        // Reallocating dynamic array
        if (count >= capacity) {
            capacity *= 2;
            ans = (int**)realloc(ans, capacity * sizeof(int*));
            *returnColumnSizes = (int*)realloc(*returnColumnSizes, capacity * sizeof(int));
        }
        
        // Adding answer
        ans[count] = (int*)malloc(size * sizeof(int));
        for (int i = 0; i < size; i++) 
            ans[count][i] = cur[i];
        
        (*returnColumnSizes)[count] = size;
        count++;
        return;
    }

    for (int i = start; i < candidatesSize; i++) {
        if (candidates[i] > target) 
            break;

        // Pruning duplicate
        if (i > start && candidates[i] == candidates[i - 1]) 
            continue;

        cur[size++] = candidates[i];
        dfs(candidates, candidatesSize, i + 1, target - candidates[i], returnColumnSizes);

        // Backtracking
        size--;
    }
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    // Sorting in ascending order
    qsort(candidates, candidatesSize, sizeof(int), compare);

    capacity = 16;
    count = 0;
    size = 0;

    // Allocating dynmaic array
    ans = (int**)malloc(capacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));
    cur = (int*)malloc(candidatesSize * sizeof(int));

    dfs(candidates, candidatesSize, 0, target, returnColumnSizes);

    *returnSize = count;
    free(cur);

    return ans;
}