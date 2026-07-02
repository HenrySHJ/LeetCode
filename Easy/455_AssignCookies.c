#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    int num1 = *(const int*)a;
    int num2 = *(const int*)b;
    
    if (num1 < num2) return -1;
    if (num1 > num2) return 1;
    return 0;
}

int findContentChildren(int* g, int gSize, int* s, int sSize) {
    qsort(g, gSize, sizeof(int), compare);
    qsort(s, sSize, sizeof(int), compare);

    int child = 0;
    int cookie = 0;

    while (child < gSize && cookie < sSize) {
        if (g[child] <= s[cookie]) {
            child++;
        }
        cookie++; 
    }

    return child;
}