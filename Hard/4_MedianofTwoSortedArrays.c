# include <stdio.h>
# include <stdlib.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int totalSize = nums1Size + nums2Size;
    int targetIdx = totalSize / 2;
    
    int p1 = 0, p2 = 0;
    int prev = 0, curr = 0;

    for (int i = 0; i <= targetIdx; i++) {
        prev = curr;
        
        if (p1 < nums1Size && (p2 >= nums2Size || nums1[p1] <= nums2[p2])) {
            curr = nums1[p1++];
        } 
        else {
            curr = nums2[p2++];
        }
    }

    if (totalSize % 2 != 0) {
        return (double)curr;
    } 
    else {
        return (double)(prev + curr) / 2.0;
    }
}
