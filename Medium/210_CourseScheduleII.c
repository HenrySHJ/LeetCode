# include <stdio.h>
# include <stdlib.h>

typedef struct Node {
    int key;
    struct Node* next;
} Node;

int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize) {
    // Making adjacency list & indegree array
    Node** adj = (Node**)calloc(numCourses, sizeof(Node*));
    int* indegree = (int*)calloc(numCourses, sizeof(int*));
    
    // Filling adjacency list & indegree array
    for (int i = 0; i < prerequisitesSize; i++) {
        int preCourse = prerequisites[i][1];
        int nextCourse = prerequisites[i][0];

        Node* node = (Node*)malloc(sizeof(Node));
        node->key = nextCourse;
        node->next = adj[preCourse];
        adj[preCourse] = node;
        indegree[nextCourse]++;
    }

    // Queue for Topological sort
    int* queue = (int*)calloc(numCourses, sizeof(int));
    int front = 0;
    int rear = 0;

    // EnQueue if indegree is 0
    int* ans = (int *)malloc(sizeof(int) * numCourses);
    int count = 0;
    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
            ans[count++] = i;
        }
    }

    // Repeat until Queue gets empty
    while (front != rear) {
        int now = queue[front++];
        Node* cur = adj[now];

        while (cur) {
            int next = cur->key;
            indegree[next]--;
            if (indegree[next] == 0) {
                queue[rear++] = next;
                ans[count++] = next;
            }
            cur = cur->next;
        }
    }
    free(queue);
    free(indegree);
    free(adj);

    // Can finish all courses
    if (count == numCourses) {
        *returnSize = count;
        return ans;
    }
    // Can't finish
    *returnSize = 0;
    free(ans);
    return NULL;
}