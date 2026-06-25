# include <stdio.h>
# include <stdlib.h>

int findGroup(int* group, int i) {
    if (group[i] != i) 
        group[i] = findGroup(group, group[i]);
    return group[i];
}

void unionGroup(int* group, int a, int b) {
    int ga = findGroup(group, a);
    int gb = findGroup(group, b);

    if (ga != gb) 
        group[ga] = gb;
}

int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    int n = edgesSize;

    // Set group features
    int* group = (int*)malloc((n + 1) * sizeof(int));
    for (int i = 1; i < n + 1; i++)
        group[i] = i;

    // MakeSet
    int* ans = (int*)malloc(2 * sizeof(int));
    for (int i = 0; i < edgesSize; i++) {
        int a = edges[i][0];
        int b = edges[i][1];

        if (findGroup(group, a) == findGroup(group, b)) {
            ans[0] = a;
            ans[1] = b;
            break;
        }
        else unionGroup(group, a, b);
    }
    *returnSize = 2;
    free(group);
    return ans;
}