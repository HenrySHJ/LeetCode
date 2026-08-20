# include <stdio.h>
# include <stdlib.h>

int compare(const void* a, const void* b) {
    int *x = *(int **)a;
    int *y = *(int **)b;

    return x[1] - y[1];
}
int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize) {
    qsort(intervals, intervalsSize, sizeof(int*), compare);

    int ans = 1;
    int f = intervals[0][1];
    for (int i = 1; i < intervalsSize; i++) {
        if (intervals[i][0] >= f) {
            f = intervals[i][1];
            ans++;
        }
    }
    return intervalsSize - ans;
}