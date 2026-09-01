# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

typedef struct {
    int x;
    int y;
    int e;
    int mask;
    int dist;
} QNode;

int minMoves(char** classroom, int classroomSize, int initialEnergy) {
    int m = classroomSize;
    int n = strlen(classroom[0]);
    int sx = 0, sy = 0;
    int litterCount = 0;
    
    // Initialize 
    int litterMap[m][n];
    memset(litterMap, -1, sizeof(litterMap));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // Find starting point
            if (classroom[i][j] == 'S') {
                sx = i; 
                sy = j;
            }

            // Finding litter coord
            else if (classroom[i][j] == 'L') 
                litterMap[i][j] = litterCount++;
        }
    }

    int maxState = 1 << litterCount;

    // Initialize queue
    int queueCapacity = m * n * maxState * (initialEnergy + 1);
    QNode* queue = (QNode*)malloc(sizeof(QNode) * queueCapacity);

    // visited : max energy with current litter state
    int*** visited = (int***)malloc(m * sizeof(int**));
    for (int i = 0; i < m; i++) {
        visited[i] = (int**)malloc(n * sizeof(int*));
        for (int j = 0; j < n; j++) {
            visited[i][j] = (int*)malloc(maxState * sizeof(int));
            for (int k = 0; k < maxState; k++) {
                visited[i][j][k] = -1;
            }
        }
    }

    int front = 0, rear = 0;
    queue[rear++] = (QNode){sx, sy, initialEnergy, 0, 0};
    visited[sx][sy][0] = initialEnergy;

    // BFS
    while (front < rear) {
        QNode cur = queue[front++];

        // Ending state
        if (cur.mask == maxState - 1) 
            return cur.dist;

        for (int k = 0; k < 4; k++) {
            int nx = cur.x + dx[k];
            int ny = cur.y + dy[k];

            // Checking valid index
            if (nx < 0 || nx >= m || ny < 0 || ny >= n) 
                continue;

            // Checking obstacles and energy
            if (classroom[nx][ny] == 'X' || cur.e <= 0) 
                continue;

            int nmask = cur.mask;
            int ne = cur.e - 1;

            // Collect litter
            if (classroom[nx][ny] == 'L' && litterMap[nx][ny] != -1) 
                nmask |= (1 << litterMap[nx][ny]);
            
            // Refill energy
            if (classroom[nx][ny] == 'R') 
                ne = initialEnergy;

            // Arrived with higher energy
            if (visited[nx][ny][nmask] < ne) {
                visited[nx][ny][nmask] = ne;
                queue[rear++] = (QNode){nx, ny, ne, nmask, cur.dist + 1};
            }
        }
    }

    // Failed
    return -1;
}