# include <stdio.h>
# include <stdlib.h>

typedef struct Node {
    int key;
    struct Node* next;
} Node;

int* findMinHeightTrees(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    // Exceptional cases
    if (n <= 2) {
        int* ans = (int *)malloc(n * sizeof(int));
        *returnSize = n;
        for (int i = 0; i < n; i++) ans[i] = i;
        return ans;
    }

    // Making bidirectional adjacency list & degree array
    Node** adj = (Node**)calloc(n, sizeof(Node*));
    int* degree = (int*)calloc(n, sizeof(int));
    
    // Filling adjacency list & degree array
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        degree[u]++; degree[v]++;

        Node* U = (Node*)malloc(sizeof(Node));
        U->key = u;
        U->next = adj[v];
        adj[v] = U;

        Node* V = (Node*)malloc(sizeof(Node));
        V->key = v;
        V->next = adj[u];
        adj[u] = V;
    }

    // Queue for Topological sort
    int* queue = (int*)malloc(n * sizeof(int));
    int front = 0;
    int rear = 0;

    // EnQueue if degree is 1
    for (int i = 0; i < n; i++) {
        if (degree[i] == 1) 
            queue[rear++] = i;
    }

    // Repeat until two nodes get left
    int remain = n;
    while (remain > 2) {
        int leaf = rear - front;
        remain -= leaf;

        // Target : leaf nodes
        for (int i = 0; i < leaf; i++) {
            int now = queue[front++];
            Node* cur = adj[now];

            // Check adjacent nodes
            while (cur) {
                int next = cur->key;
                degree[next]--;
                // EnQueue if degree is 1
                if (degree[next] == 1) 
                    queue[rear++] = next;
                cur = cur->next;
            }
        }
    }

    // Set answer array
    int* ans = (int*)calloc((rear - front), sizeof(int));
    *returnSize = rear - front;

    // append answer
    int idx = 0;
    while (front < rear)
        ans[idx++] = queue[front++];
    
    free(queue);
    free(degree);
    free(adj);

    return ans;
}