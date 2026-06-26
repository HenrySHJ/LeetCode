# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

// dfs
void dfs(int** rooms, int* roomsColSize, int now, bool* visited, int* count) {
    visited[now] = true;
    (*count)++;

    for (int i = 0; i < roomsColSize[now]; i++) {
        int nxt = rooms[now][i];
        
        if (!visited[nxt]) {
            dfs(rooms, roomsColSize, nxt, visited, count);
        }
    }
}

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    bool* visited = (bool*)calloc(roomsSize, sizeof(bool));
    int count = 0;

    // start dfs from room 0
    dfs(rooms, roomsColSize, 0, visited, &count);

    free(visited);
    return count == roomsSize;
}