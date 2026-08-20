# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

int ans;

int min(int a, int b) {
    return (a < b) ? a : b;
}

void chooseTopping(int* toppingCosts, int m, int idx, int sum, int target) {
    // Update answer
    if (abs(sum - target) < abs(ans - target)) 
        ans = sum;

    else if (abs(sum - target) == abs(ans - target))
        ans = min(sum, ans);
    
    // Pruning
    if (sum >= target || idx == m) {
        return;
    }
    
    for (int count = 0; count <= 2; count++) {
        chooseTopping(toppingCosts, m, idx + 1, sum + toppingCosts[idx] * count, target);
    }
}

int closestCost(int* baseCosts, int baseCostsSize, int* toppingCosts, int toppingCostsSize, int target) {
    int n = baseCostsSize;
    int m = toppingCostsSize;

    ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        chooseTopping(toppingCosts, m, 0, baseCosts[i], target);
    }

    return ans;
}