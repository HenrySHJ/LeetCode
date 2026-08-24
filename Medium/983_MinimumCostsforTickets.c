# include <stdio.h>
# include <stdbool.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

int mincostTickets(int* days, int daysSize, int* costs, int costsSize) {
    int lastDay = days[daysSize - 1];
    
    int isTravelDay[366] = {0};
    for (int i = 0; i < daysSize; i++) {
        isTravelDay[days[i]] = 1;
    }

    int dp[366] = {0};

    for (int day = 1; day <= lastDay; day++) {
        if (!isTravelDay[day]) {
            dp[day] = dp[day - 1];
            continue;
        }

        int cost1 = dp[day - 1] + costs[0];
        int cost7 = dp[(day - 7 >= 0) ? day - 7 : 0] + costs[1];
        int cost30 = dp[(day - 30 >= 0) ? day - 30 : 0] + costs[2];

        dp[day] = min(cost1, min(cost7, cost30));
    }

    return dp[lastDay];
}