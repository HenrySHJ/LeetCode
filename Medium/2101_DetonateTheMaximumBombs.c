# include <stdio.h>
# include <stdlib.h>
# include <math.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

int maximumDetonation(int** bombs, int bombsSize, int* bombsColSize) {
    int n = bombsSize;
    
    // Reset adjacency list
    Node** adj = (Node**)calloc(n, sizeof(Node*));
    
    // Connect edge if it can detonate next bomb
    for (int i = 0; i < n; i++) {
        long long x1 = bombs[i][0];
        long long y1 = bombs[i][1];
        
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            
            long long x2 = bombs[j][0];
            long long y2 = bombs[j][1];
            
            long long dist = (long long)(x1 - x2) * (x1 - x2) + (long long)(y1 - y2) * (y1 - y2);
            long long r1 = (long long)bombs[i][2] * bombs[i][2];
            
            if (dist <= r1) {
                Node* node = (Node*)malloc(sizeof(Node));
                node->vertex = j;
                node->next = adj[i];
                adj[i] = node;
            }
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        int* queue = (int*)malloc(n * sizeof(int));
        int* detonated = (int*)calloc(n, sizeof(int));

        int front = 0, rear = 0;
        int count = 0;
        
        queue[rear++] = i;
        detonated[i] = 1;
        count++;
        
        while (front != rear) {
            int now = queue[front++];
            Node* cur = adj[now];

            while (cur) {
                int nxt = cur->vertex;
                if (!detonated[nxt]) {
                    detonated[nxt] = 1;
                    queue[rear++] = nxt;
                    count++;
                }
                cur = cur->next;
            }
        }
        
        // Update answer
        if (count > ans)
            ans = count;
        
        free(detonated);
        free(queue);
    }
    
    free(adj);
    return ans;
}