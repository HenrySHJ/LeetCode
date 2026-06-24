# include <stdio.h>
# include <stdlib.h>

int findJudge(int n, int** trust, int trustSize, int* trustColSize) {
    int* indegree = (int *)calloc(n + 1, sizeof(int));
    int* outdegree = (int *)calloc(n + 1, sizeof(int));
    for (int i = 0; i < trustSize; i++) {
        int a = trust[i][0];
        int b = trust[i][1];
        indegree[b]++;
        outdegree[a]++;
    }

    for (int i = 1; i < n + 1; i++) {
        if (indegree[i] == n - 1 && outdegree[i] == 0) return i;
    }
    free(outdegree);
    free(indegree);
    return -1;
}