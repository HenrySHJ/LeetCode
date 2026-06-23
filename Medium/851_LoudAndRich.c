# include <stdio.h>
# include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// DFS with memoization
int dfs(int num, struct Node** graph, int* quiet, int* answer) {
    // Already memoized
    if (answer[num] != -1) 
        return answer[num];
    
    // Self set answer
    int least_loud = num;
    
    // DFS through adj
    Node* curr = graph[num];
    while (curr != NULL) {
        int richer = curr->vertex;
        int candidate = dfs(richer, graph, quiet, answer);
        
        // Backtracking
        if (quiet[candidate] < quiet[least_loud]) 
            least_loud = candidate;

        curr = curr->next;
    }
    
    answer[num] = least_loud;
    return answer[num];
}

int* loudAndRich(int** richer, int richerSize, int* richerColSize, int* quiet, int quietSize, int* returnSize) {
    // Setting adjacency list & features
    int n = quietSize;
    Node** adj = (Node**)calloc(n, sizeof(Node*));
    int* answer = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) 
        answer[i] = -1;
    
    // Filling adjacency list
    for (int i = 0; i < richerSize; i++) {
        int a = richer[i][0];
        int b = richer[i][1];

        Node* node = (Node*)malloc(sizeof(Node));
        node->vertex = a;
        node->next = adj[b];
        adj[b] = node;
    }

    // load dfs
    for (int i = 0; i < n; i++)
        dfs(i, adj, quiet, answer);

    free(adj);
    *returnSize = n;
    return answer;
}