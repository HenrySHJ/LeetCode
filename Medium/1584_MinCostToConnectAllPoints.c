# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct Node {
    int vertex;
    int weight;
    struct Node* next;
} Node;

// Return absolute value
int abs(int x) {
    if (x < 0) return x * -1;
    return x;
}

// Prim Algorithm
int minCostConnectPoints(int** points, int pointsSize, int* pointsColSize) {
    int n = pointsSize;
    
    // Making adjacency list and vertex features
    Node** adj = (Node**)calloc(n, sizeof(Node*));
    int* key = (int*)malloc(n * sizeof(int));
    int* inMST = (int*)calloc(n, sizeof(int));

    // Fill key as MAXIMUM
    for (int i = 0; i < n; i++) 
        key[i] = INT_MAX;
    
    // Filling adjacent List
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int dist = abs(points[j][0] - points[i][0]) + abs(points[j][1] - points[i][1]);
            
            Node* edge1 = (Node*)malloc(sizeof(Node));
            edge1->vertex = j;
            edge1->weight = dist;
            edge1->next = adj[i];
            adj[i] = edge1;

            Node* edge2 = (Node*)malloc(sizeof(Node));
            edge2->vertex = i;
            edge2->weight = dist;
            edge2->next = adj[j];
            adj[j] = edge2;
        }
    }

    // Starting Prim Algorithm by Vertex 0
    key[0] = 0;
    int totalCost = 0;

    // Selecting n nodes for MST
    for (int step = 0; step < n; step++) {
        // Find Vertex u
        int u = -1;
        int minVal = INT_MAX;
        // Vertex u has lowest value
        for (int i = 0; i < n; i++) {
            if (!inMST[i] && key[i] < minVal) {
                minVal = key[i];
                u = i;
            }
        }

        // Found all Vertex
        if (u == -1) break;
        inMST[u] = 1;
        totalCost += minVal;

        // Finding adjacent node v from node u
        Node* cur = adj[u];
        while (cur) {
            int v = cur->vertex;
            int w = cur->weight;
            // update distance near node u
            if (!inMST[v] && w < key[v])
                key[v] = w;
            cur = cur->next;
        }
    }
    free(adj);
    free(key);
    free(inMST);

    return totalCost;
}