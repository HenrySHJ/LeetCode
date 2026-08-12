# include <stdio.h>
# include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int** adj;

int capacity;
int** ans;
int count;

int* path;
int** rcs;

void dfs(int graphSize, int* graphColSize, int cur, int pathSize) {
    // Found target node
    if (cur == graphSize - 1) {
        // Add target node to path
        path[pathSize] = graphSize - 1;

        // Add answer to dynamic array
        ans[count] = (int*)malloc((pathSize + 1) * sizeof(int));
        for (int i = 0; i < pathSize + 1; i++) 
            ans[count][i] = path[i];

        (*rcs)[count] = pathSize + 1;
        count++;

        // Reallocate dynamic array
        if (count >= capacity) {
            capacity *= 2;
            ans = (int**)realloc(ans, capacity * sizeof(int*));
            *rcs = (int*)realloc(*rcs, capacity * sizeof(int));
        }

        return;
    }

    for (int i = 0; i < graphColSize[cur]; i++) {
        path[pathSize] = cur;
        dfs(graphSize, graphColSize, adj[cur][i], pathSize + 1);
    }
    
}

int** allPathsSourceTarget(int** graph, int graphSize, int* graphColSize, int* returnSize, int** returnColumnSizes) {
    // New global pointer at graph
    adj = graph;

    // Initialize dynamic ans array
    capacity = 2;
    ans = (int**)malloc(capacity * sizeof(int*));
    count = 0;

    // Initialize path array
    path = (int*)malloc(graphSize * sizeof(int));
    int pathSize = 0;
    rcs = returnColumnSizes;
    *rcs = (int*)malloc(graphSize * sizeof(int));
    
    // Start DFS + Backtracking
    dfs(graphSize, graphColSize, 0, 0);

    *returnSize = count;    
    return ans;
}