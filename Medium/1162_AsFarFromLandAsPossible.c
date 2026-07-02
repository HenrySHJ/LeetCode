# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

int max(int a, int b) {
    if (a <= b) return b;
    else return a;
}

typedef struct {
    int x;
    int y;
} QNode;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int maxDistance(int** grid, int gridSize, int* gridColSize) {
    int row = gridSize;
    int col = gridColSize[0];
    
    // Set Queue for bfs
    QNode* queue = (QNode*)malloc(row * col * sizeof(QNode));
    int front = 0, rear = 0;

    // dp array for distance
    int** dist = (int**)malloc(row * sizeof(int*));
    for (int i = 0; i < row; i++) {
        dist[i] = (int*)malloc(col * sizeof(int));
        for (int j = 0; j < col; j++) {
            if (grid[i][j] == 1) {
                dist[i][j] = 0; 
                queue[rear++] = (QNode){i, j}; 
            } else {
                dist[i][j] = -1;
            }
        }
    }

    if (rear == 0 || rear == row * col) {
        for (int i = 0; i < row; i++) free(dist[i]);
        free(dist); 
        free(queue);
        return -1;
    }

    int max_dist = -1;

    // Start BFS 
    while (front != rear) {
        QNode now = queue[front++];
        
        for (int k = 0; k < 4; k++) {
            int nx = now.x + dx[k];
            int ny = now.y + dy[k];

            // Checking if valid index
            if (0 <= nx && nx < row && 0 <= ny && ny < col) {
                if (dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[now.x][now.y] + 1; 
                    max_dist = MAX(max_dist, dist[nx][ny]);
                    queue[rear++] = (QNode){nx, ny};
                }
            }
        }
    }

    for (int i = 0; i < row; i++) {
        free(dist[i]);
    }
    free(dist);
    free(queue);

    return max_dist;
}