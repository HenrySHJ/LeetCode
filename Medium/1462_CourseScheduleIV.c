# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

bool* checkIfPrerequisite(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    int n = numCourses;

    // Set adjacency list
    Node** adj = (Node**)calloc(n, sizeof(Node*));
    int* indegree = (int*)calloc(n, sizeof(int));

    // Set prerequisite array
    bool** isPre = (bool**)malloc(n * sizeof(bool*));
    for (int i = 0; i < n; i++) 
        isPre[i] = (bool*)calloc(n, sizeof(bool));

    // Fill adjacency list
    for (int i = 0; i < prerequisitesSize; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];

        Node* node = (Node*)malloc(sizeof(Node));
        node->vertex = b;
        node->next = adj[a];
        adj[a] = node;

        indegree[b]++;
        isPre[a][b] = true;
    }

    // Set queue for topological sort
    int* queue = (int*)calloc(n, sizeof(int));
    int front = 0;
    int rear = 0;

    // EnQueue if indegree is 0
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) 
            queue[rear++] = i;
    }

    // Repeat while queue gets empty
    while (front != rear) {
        int now = queue[front++];
        Node* cur = adj[now];

        while (cur) {
            int nxt = cur->vertex;

            // Propagate
            for (int i = 0; i < n; i++) {
                if (isPre[i][now])
                    isPre[i][nxt] = true;
            }

            indegree[nxt]--;
            if (indegree[nxt] == 0) 
                queue[rear++] = nxt;
            
            cur = cur->next;
        }
    }   

    // Query answer
    bool* answer = (bool*)malloc(queriesSize * sizeof(bool));
    for (int i = 0; i < queriesSize; i++) {
        int num1 = queries[i][0];
        int num2 = queries[i][1];

        answer[i] = isPre[num1][num2];
    }

    free(queue);
    free(indegree);
    free(adj);

    *returnSize = queriesSize;
    return answer;
}