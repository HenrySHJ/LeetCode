# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct Node {
    int key;
    struct Node* next;
} Node;

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    // Setting up adjacency list & indegree array;
    Node** adj = (Node **)calloc(numCourses, sizeof(Node*));
    int* indegree = (int *)calloc(numCourses, sizeof(int));

    // Making adjacency list
    for (int i = 0; i < prerequisitesSize; i++) {
        int pre_course = prerequisites[i][1];
        int next_course = prerequisites[i][0];

        Node* node = (Node *)malloc(sizeof(Node));
        node->key = next_course;
        node->next = adj[pre_course];
        adj[pre_course] = node;
        indegree[next_course]++;
    }

    // Queue for Topological sort
    int* queue = (int *)calloc(numCourses, sizeof(int));
    int front = 0;
    int rear = 0;

    // EnQueue if indegree is 0
    int count = 0; 
    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i; 
            count++;
        }
    }

    // Repeat until queue gets empty
    while (front != rear) {
        int now = queue[front++];
        Node* cur = adj[now];
        
        // adjacent node 
        while (cur) {
            int next = cur->key;
            indegree[next]--;
            // EnQueue if indegree is 0
            if (indegree[next] == 0) {
                queue[rear++] = next;
                count++;
            }
            cur = cur->next;    
        }
    }

    // free memeory
    free(queue);
    free(indegree);
    free(adj);

    if (count == numCourses) return true;
    else return false;
}