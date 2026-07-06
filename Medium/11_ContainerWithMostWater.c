#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int max_area = 0;

    while (left < right) {
        int cur_width = right - left;
        int cur_height = MIN(height[left], height[right]);
        int cur_area = cur_width * cur_height;

        max_area = MAX(max_area, cur_area);

        if (height[left] < height[right])
            left++;
        else 
            right--;
    }

    return max_area;
}