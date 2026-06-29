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

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize) {
    // Initialize Group
    int* group = (int*)malloc(isConnectedSize * sizeof(int));
    for (int i = 0; i < isConnectedSize; i++) {
        group[i] = i;
    }

    // Connect groups
    for (int i = 0; i < isConnectedSize; i++) {
        for (int j = 0; j < isConnectedColSize[i]; j++) {
            if (i == j) continue;
            else if (isConnected[i][j]) 
                unionGroup(group, i , j);  
        }
    }

    // Find Province
    int province = 0;
    for (int i = 0; i < isConnectedSize; i++) {
        if (group[i] == i) province++;
    }
    free(group);
    return province;
}