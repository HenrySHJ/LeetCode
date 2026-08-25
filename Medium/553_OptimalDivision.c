# include <stdio.h>
# include <stdlib.h>
# include <string.h>

char* optimalDivision(int* nums, int numsSize) {
    char* result = (char*)malloc(10000 * sizeof(char));

    if (numsSize == 1) {
        sprintf(result, "%d", nums[0]);
        return result;
    }
    if (numsSize == 2) {
        sprintf(result, "%d/%d", nums[0], nums[1]);
        return result;
    }

    sprintf(result, "%d/(%d", nums[0], nums[1]);
    for (int i = 2; i < numsSize; i++) {
        sprintf(result + strlen(result), "/%d", nums[i]);
    }
    strcat(result, ")");

    return result;
}