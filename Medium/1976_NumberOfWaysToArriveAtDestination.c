#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INF 1e18 
#define MOD 1000000007

int getMinVertex(long long* dist, bool* visited, int n) {
    long long min_val = INF;
    int min_index = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] < min_val) {
            min_val = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

int countPaths(int n, int** roads, int roadsSize, int* roadsColSize) {
    // Reset adjacency list
    long long** adj = (long long**)malloc(n * sizeof(long long*));
    for (int i = 0; i < n; i++) {
        adj[i] = (long long*)malloc(n * sizeof(long long));
        for (int j = 0; j < n; j++) {
            adj[i][j] = INF;
        }
    }

    // Fill adjacency list
    for (int i = 0; i < roadsSize; i++) {
        int u = roads[i][0];
        int v = roads[i][1];
        long long w = roads[i][2];
        adj[u][v] = w;
        adj[v][u] = w;
    }

    // Set distance features
    long long* dist = (long long*)malloc(n * sizeof(long long));
    long long* ways = (long long*)calloc(n, sizeof(long long));
    bool* visited = (bool*)calloc(n, sizeof(bool));

    // Reset features : ways[i] -> count to reach 0->i
    for (int i = 0; i < n; i++) dist[i] = INF;
    dist[0] = 0;
    ways[0] = 1;

    // Linear Search Priority Queue
    for (int i = 0; i < n; i++) {
        // Extract-Min(Queue)
        int u = getMinVertex(dist, visited, n);
        if (u == -1) break;

        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (adj[u][v] != INF && !visited[v]) {
                // New way for Shortest Path
                if (dist[u] + adj[u][v] < dist[v]) {
                    dist[v] = dist[u] + adj[u][v];
                    ways[v] = ways[u];
                }
                // Another way for Shortest Path
                else if (dist[u] + adj[u][v] == dist[v]) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }
    }

    int result = ways[n - 1];

    free(dist);
    free(ways);
    free(visited);
    for (int i = 0; i < n; i++) free(adj[i]);
    free(adj);

    return result;
}