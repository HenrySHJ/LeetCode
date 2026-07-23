# include <stdio.h>
# include <stdlib.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int idx1 = 0;
    int idx2 = 0;
    int a_idx = 0;

    int ans[m + n];

    while (idx1 < m && idx2 < n) {
        if (nums1[idx1] <= nums2[idx2]) 
            ans[a_idx++] = nums1[idx1++];
        else 
            ans[a_idx++] = nums2[idx2++];
    }

    while (idx1 < m) {
        ans[a_idx++] = nums1[idx1++];
    }
    while (idx2 < n) {
        ans[a_idx++] = nums2[idx2++];
    }

    for (int i = 0; i < n + m; i++)
        nums1[i] = ans[i];
}