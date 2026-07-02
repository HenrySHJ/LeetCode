#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int maxProfit(int* prices, int pricesSize, int fee) {
    // Set base case
    int hold = -prices[0];
    int cash = 0;

    // By Topological order
    for (int i = 1; i < pricesSize; i++) {
        int prevCash = cash;

        cash = max(cash, hold + prices[i] - fee);
        hold = max(hold, prevCash - prices[i]);
    }

    return cash;
}