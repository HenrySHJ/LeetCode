# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <math.h>

long long min(long long a, long long b) {
    return a < b ? a : b;
}

long long minMergeCost(int** lists, int listsSize, int* listsColSize) {
    long long dp[1 << listsSize];
    long long len[1 << listsSize];
    long long med[1 << listsSize];

    for (int i = 0; i < (1 << listsSize); i++) {
        len[i] = 0;
        med[i] = 0;
    }

    // Array for saving sorted elements for every mask
    int** sortedArr = (int**)malloc((1 << listsSize) * sizeof(int*));

    for (int mask = 1; mask < (1 << listsSize); mask++) {
        // Copy lists[i] if only one bit
        if ((mask & (mask - 1)) == 0) {
            int idx = __builtin_ctz(mask); // LSB index
            int count = listsColSize[idx];
            
            len[mask] = count;
            sortedArr[mask] = (int*)malloc(count * sizeof(int));

            for (int i = 0; i < count; i++) 
                sortedArr[mask][i] = lists[idx][i];
            
            med[mask] = sortedArr[mask][(count - 1) / 2];
            continue;
        }

        // Two Pointer merge if more than one bit
        int sub1 = mask & (-mask); // Find lowest bit
        int sub2 = mask ^ sub1;    // Find other bits

        int len1 = len[sub1];
        int len2 = len[sub2];
        int totalLen = len1 + len2;

        len[mask] = totalLen;
        sortedArr[mask] = (int*)malloc(totalLen * sizeof(int));

        int p1 = 0, p2 = 0;
        int k = 0;
        int* arr1 = sortedArr[sub1];
        int* arr2 = sortedArr[sub2];

        // Merge Sort
        while (p1 < len1 && p2 < len2) {
            if (arr1[p1] <= arr2[p2]) 
                sortedArr[mask][k++] = arr1[p1++];
            else 
                sortedArr[mask][k++] = arr2[p2++];
        }
        while (p1 < len1) 
            sortedArr[mask][k++] = arr1[p1++];
        while (p2 < len2) 
            sortedArr[mask][k++] = arr2[p2++];

        // Found median
        med[mask] = sortedArr[mask][(totalLen - 1) / 2];
    }

    // Set base case
    for (int mask = 0; mask < (1 << listsSize); mask++) 
        dp[mask] = LLONG_MAX;
    
    for (int i = 0; i < listsSize; i++) 
        dp[1 << i] = 0;

    // Tabulation : Submask DP
    for (int mask = 1; mask < (1 << listsSize); mask++) {
        // Cannot divide if only has one bit
        if ((mask & (mask - 1)) == 0) 
            continue;

        // Trying every submasks
        for (int sub = (mask - 1) & mask; sub > 0; sub = (sub - 1) & mask) {
            int other = mask ^ sub;
            // Handling duplicate
            if (sub > other) 
                continue;

            // combine if both computed
            if (dp[sub] != LLONG_MAX && dp[other] != LLONG_MAX) {
                long long cost = len[sub] + len[other] + llabs(med[sub] - med[other]);
                dp[mask] = min(dp[mask], dp[sub] + dp[other] + cost);
            }
        }
    }

    long long result = dp[(1 << listsSize) - 1];
    return result;
}