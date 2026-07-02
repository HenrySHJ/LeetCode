#include <stdio.h>
#include <limits.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int maxProfit(int* prices, int pricesSize) {
    if (pricesSize <= 1) return 0;

    int buy1 = INT_MAX;
    int profit1 = 0;
    int buy2 = INT_MAX;
    int profit2 = 0;

    for (int i = 0; i < pricesSize; i++) {
        buy1 = MIN(buy1, prices[i]);
        profit1 = MAX(profit1, prices[i] - buy1);
        
        
        buy2 = MIN(buy2, prices[i] - profit1);
        profit2 = MAX(profit2, prices[i] - buy2);
    }

    return profit2;
}