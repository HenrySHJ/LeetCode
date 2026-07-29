# include <stdio.h>
# include <stdlib.h>


int maxProfit(int k, int* prices, int pricesSize) {
    // Maximum profit when buy/sold on jth transaction
    int* buy = (int*)malloc((k + 1) * sizeof(int));
    int* sell = (int*)malloc((k + 1) * sizeof(int));

    // Reset value
    for (int i = 0; i <= k; i++) {
        buy[i] = -1000000;
        sell[i] = 0;
    }

    for (int i = 0; i < pricesSize; i++) {
        int p = prices[i];

        
        for (int j = 1; j <= k; j++) {
            buy[j] = MAX(buy[j], sell[j - 1] - p);
            sell[j] = MAX(sell[j], buy[j] + p);
        }
    }

    int ans = sell[k];

    free(sell);
    free(buy);

    return ans;
}