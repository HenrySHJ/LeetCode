#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int findGroup(int* group, int i) {
    if (group[i] == i) return i;
    return group[i] = findGroup(group, group[i]);
}

void unionGroup(int* group, int a, int b) {
    int groupA = findGroup(group, a);
    int groupB = findGroup(group, b);
    if (groupA != groupB) group[groupA] = groupB;
}

bool validPath(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination) {
    // Initialize group numbers
    int* group = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        group[i] = i;

    // Union Groups
    for (int i = 0; i < edgesSize; i++)    
        unionGroup(group, edges[i][0], edges[i][1]);
    
    bool result = (findGroup(group, source) == findGroup(group, destination));
    free(group);
    
    return result;
}