# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int maximalNetworkRank(int n, int** roads, int roadsSize, int* roadsColSize) {
    bool connected[n][n];
    int count[n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            connected[i][j] = false;
        
    for (int i = 0; i < n; i++)
        count[i] = 0;

    for (int i = 0; i < roadsSize; i++) {
        int u = roads[i][0];
        int v = roads[i][1];
        count[u]++;
        count[v]++;

        connected[u][v] = true;
        connected[v][u] = true;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++)
            ans = max(ans, count[i] + count[j] - (connected[i][j] ? 1 : 0));
    }
    return ans;
}