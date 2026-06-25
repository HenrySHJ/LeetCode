# include <stdio.h>
# include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

int* findSmallestSetOfVertices(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    // Set indegree features
    int* indegree = (int*)calloc(n, sizeof(int));

    // Fill indegree
    for (int i = 0; i < edgesSize; i++) {
        int b = edges[i][1];
        indegree[b]++;
    }

    // answer if indegree is 0
    int* ans = (int *)malloc(n * sizeof(int));
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            ans[count++] = i;
        }
    }
    *returnSize = count;
    free(indegree);
    return ans;
}