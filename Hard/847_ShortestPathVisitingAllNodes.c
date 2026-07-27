#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// BFS Queue struct
typedef struct {
    int node;
    int mask;
} State;

int shortestPathLength(int** graph, int graphSize, int* graphColSize) {
    int n = graphSize;
    int targetMask = (1 << n) - 1;

    // Initialize dp table
    // dp[node][mask] : minimum movement when currently on node, and visited checked by mask
    int dp[12][1 << 12];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << n); j++) {
            dp[i][j] = -1;
        }
    }

    // Queue for BFS (For every possibilities)
    int maxStates = n * (1 << n);
    State* queue = (State*)malloc(maxStates * sizeof(State));
    int front = 0, rear = 0;

    // Multi-Souce BFS -> Set base case and enQueue
    for (int i = 0; i < n; i++) {
        dp[i][1 << i] = 0;
        queue[rear++] = (State){i, 1 << i};
    }

    // Search BFS
    while (front < rear) {
        State cur = queue[front++];
        int u = cur.node;
        int mask = cur.mask;

        // Is the shortest path if made it
        if (mask == targetMask) {
            int ans = dp[u][mask];
            free(queue);
            return ans;
        }

        // Searching neighbor nodes
        for (int i = 0; i < graphColSize[u]; i++) {
            int next = graph[u][i];             
            int nextMask = mask | (1 << next);   

            // unvisited masks
            if (dp[next][nextMask] == -1) {
                dp[next][nextMask] = dp[u][mask] + 1; 
                queue[rear++] = (State){next, nextMask};
            }
        }
    }

    free(queue);
    return 0;
}