# include <stdio.h>
# include <stdlib.h>

int findGroup(int* group, int i) {
    if (group[i] != i) 
        group[i] = findGroup(group, group[i]);
    return group[i];
}

void unionGroup(int* group, int a, int b) {
    a = findGroup(group, a);
    b = findGroup(group, b);
    if (a != b)
        group[a] = b;
}

int* findRedundantDirectedConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    *returnSize = 2;
    int firstIdx = -1;
    int secondIdx = -1;

    // Initialize indegree & group
    int* indegree = (int*)calloc(edgesSize + 1, sizeof(int));
    int* group = (int*)malloc((edgesSize + 1) * sizeof(int));
    for (int i = 1; i < (edgesSize + 1); i++)
        group[i] = i;

    // Find edges which indegree is 2
    for (int i = 0; i < edgesSize; i++) {
        int v = edges[i][1];
        if (indegree[v] > 0) {
            firstIdx = indegree[v] - 1; 
            secondIdx = i;
            break;
        }
        indegree[v] = i + 1;
    }

    // Union-Find
    int* ans = (int*)malloc(2 * sizeof(int));
    for (int i = 0; i < edgesSize; i++) {
        if (i == secondIdx) continue;

        int u = edges[i][0];
        int v = edges[i][1];

        if (findGroup(group, u) == findGroup(group, v)) {
            if (firstIdx != -1) {
                ans[0] = edges[firstIdx][0];
                ans[1] = edges[secondIdx][1];
            } 
            else {
                ans[0] = u;
                ans[1] = v;
            }
            free(indegree); free(group);
            return ans;
        }
        unionGroup(group, u, v);
    }

    free(indegree);
    free(group);
    ans[0] = edges[secondIdx][0];
    ans[1] = edges[secondIdx][1];
    return ans;
}