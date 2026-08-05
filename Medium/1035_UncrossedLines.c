# include <stdio.h>
# include <stdlib.h>

int max(int a, int b) {
    if (a < b) return b;
    else return a;
}

int maxUncrossedLines(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    // dp[i][j] : maximum line when used i on nums1 and j one nums2
    int dp[nums1Size + 1][nums2Size + 1];
    for (int i = 0; i < nums1Size + 1; i++) {
        for (int j = 0; j < nums2Size + 1; j++) 
            dp[i][j] = 0;
    }

    for (int i = 0; i < nums1Size; i++) {
        for (int j = 0; j < nums2Size; j++) {
            if (nums1[i] == nums2[j]) 
                dp[i + 1][j + 1] = dp[i][j] + 1;
            else 
                dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
        }
    }

    return dp[nums1Size][nums2Size];    
}