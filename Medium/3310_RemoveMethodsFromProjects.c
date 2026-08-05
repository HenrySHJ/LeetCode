#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* remainingMethods(int n, int k, int** invocations, int invocationsSize, int* invocationsColSize, int* returnSize) {
    // Calculating all outdegrees for making graph
    int* degree = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < invocationsSize; i++) {
        degree[invocations[i][0]]++;
    }

    // Making new graph as adjacency list 
    int** adj = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) 
        adj[i] = (int*)malloc(degree[i] * sizeof(int));

    // Filling adjacency list
    int* idx = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < invocationsSize; i++) {
        int u = invocations[i][0];
        int v = invocations[i][1];
        adj[u][idx[u]++] = v;
    }
    free(idx);

    // Finding suspicious vertex
    bool* suspicious = (bool*)calloc(n, sizeof(bool));
    int* queue = (int*)malloc(n * sizeof(int));
    int front = 0, rear = 0;

    queue[rear++] = k;
    suspicious[k] = true;

    while (front < rear) {
        int u = queue[front++];
        for (int i = 0; i < degree[u]; i++) {
            int v = adj[u][i];
            if (!suspicious[v]) {
                suspicious[v] = true;
                queue[rear++] = v;
            }
        }
    }
    free(queue);

    // Checking if other vertex invoke suspicious vertex
    bool canRemove = true;
    for (int i = 0; i < invocationsSize; i++) {
        int u = invocations[i][0];
        int v = invocations[i][1];
        if (!suspicious[u] && suspicious[v]) {
            canRemove = false;
            break;
        }
    }

    int* ans = (int*)malloc(n * sizeof(int));
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (!canRemove || !suspicious[i]) {
            ans[count++] = i;
        }
    }

    for (int i = 0; i < n; i++) 
        free(adj[i]);
    free(adj);    
    free(degree);
    free(suspicious);

    *returnSize = count;
    return ans;
}