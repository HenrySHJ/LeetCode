# include <stdio.h>
# include <stdlib.h>

int findCenter(int** edges, int edgesSize, int* edgesColSize) {
    int n = edgesSize + 1;
    int* indegree = (int*)calloc(n + 1, sizeof(int));

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        indegree[u]++;
        indegree[v]++;
    }    

    for (int i = 1; i < n + 1; i++) 
        if (indegree[i] == edgesSize) return i;

    free(indegree);
    return 0;
}

/* Shortcut only for this problem
int findCenter(int** edges, int edgesSize, int* edgesColSize) {
    int a = edges[0][0];
    int b = edges[0][1];

    if (edges[1][0] == a) return a;
    else if (edges[1][1] == a) return a;
    else return b; 
}
*/