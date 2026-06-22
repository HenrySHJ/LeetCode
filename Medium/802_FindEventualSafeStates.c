# include <stdio.h>
# include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

int* eventualSafeNodes(int** graph, int graphSize, int* graphColSize, int* returnSize) {
    // Setting adjacency list && indegree array
    Node** adj = (Node**)calloc(graphSize, sizeof(Node*));
    int* indegree = (int*)calloc(graphSize, sizeof(int));

    // Filling adjacency list by reversing (u, v)
    for (int i = 0; i < graphSize; i++) {
        int u = i;
        for (int j = 0; j < graphColSize[i]; j++) {
            int v = graph[i][j];
            Node* node = (Node*)malloc(sizeof(Node));
            node->vertex = u;
            node->next = adj[v];
            adj[v] = node;
            indegree[u]++;
        }
    }

    // Queue for topological sort
    int* queue = (int*)malloc(graphSize * sizeof(int));
    int front = 0;
    int rear = 0;

    // EnQueue if indegree is 0
    int* ans = (int*)malloc(graphSize * sizeof(int));
    int count = 0;
    for (int i = 0; i < graphSize; i++) {
        if (indegree[i] == 0) 
            queue[rear++] = i;
    }

    // Repeat until queue gets empty
    while (front != rear) {
        int now = queue[front++];
        Node* cur = adj[now];

        // Check adjacent nodes
        while (cur) {
            int next = cur->vertex;
            indegree[next]--;
            if (indegree[next] == 0) 
                queue[rear++] = next;
            cur = cur->next;
        }
    }

    // find answer
    for (int i = 0; i < graphSize; i++)
        if (indegree[i] == 0) ans[count++] = i;

    free(queue);
    free(indegree);
    free(adj);

    *returnSize = count;
    return ans;
}