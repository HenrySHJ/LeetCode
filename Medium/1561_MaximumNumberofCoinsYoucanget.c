# include <stdio.h>
# include <stdlib.h>

int compare(const void* a, const void* b) {
    int num1 = *(int*)a;
    int num2 = *(int*)b;
    return (num1 > num2) - (num1 < num2);
}

int maxCoins(int* piles, int pilesSize) {
    // Sort by ascending order
    qsort(piles, pilesSize, sizeof(int), compare); 

    int n = pilesSize / 3;
    int ans = 0;
    for (int i = n; i < pilesSize; i += 2) 
        ans += piles[i];

    return ans;
}