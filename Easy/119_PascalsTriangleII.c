#include <stdio.h>
#include <stdlib.h>

int* getRow(int rowIndex, int* returnSize) {
    *returnSize = rowIndex + 1;
    int* data = (int*)calloc(*returnSize, sizeof(int));
    
    data[0] = 1;

    // Going backward
    for (int i = 1; i <= rowIndex; i++) {
        for (int j = i; j > 0; j--) {
            data[j] = data[j] + data[j - 1];
        }
    }

    return data;
}