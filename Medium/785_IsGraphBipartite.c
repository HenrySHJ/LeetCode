# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

bool isBipartite(int** graph, int graphSize, int* graphColSize) {
    // Initalize Group
    int* group = (int*)malloc(graphSize * sizeof(int));    
    for (int i = 0; i < graphSize; i++)
        group[i] = -1;
        
    // Start BFS
    for (int i = 0; i < graphSize; i++) {
        // Skip if visited node
        if (group[i] != -1) 
            continue;

        // Set Linear Queue for BFS
        int* queue = (int*)calloc(graphSize, sizeof(int));
        int front = 0;
        int rear = 0;
        group[i] = 0;
        queue[rear++] = i;

        while (front != rear) {
            int cur = queue[front++];
            for (int j = 0; j < graphColSize[cur]; j++) {
                int nxt = graph[cur][j];
                // EnQueue unvisited node
                if (group[nxt] == -1)
                    queue[rear++] = nxt;

                // Same group between adjacent node
                if (group[cur] == group[nxt]) {
                    free(queue);
                    free(group);
                    return false;
                }
                // Pairing new groups
                else if (group[cur] == 0 && group[nxt] == -1) 
                    group[nxt] = 1;
                else if (group[cur] == 1 && group[nxt] == -1)
                    group[nxt] = 0;
            }
        }
        free(queue);
    }
    return true;
}