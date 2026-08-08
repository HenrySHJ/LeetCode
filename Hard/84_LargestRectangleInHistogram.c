# include <stdio.h>
# include <stdlib.h>

int largestRectangleArea(int* heights, int heightsSize) {
    int n = heightsSize;

    int* stack = (int*)malloc((n + 1) * sizeof(int));
    int top = -1;

    int ans = 0;
    for (int i = 0; i < n + 1; i++) {
        int cur_height = (i == n) ? 0 : heights[i];
        while (top >= 0 && heights[stack[top]] >= cur_height) {
            int h = heights[stack[top--]];

            int width = (top == -1) ? i : (i - stack[top] - 1);

            int area = h * width;
            if (area > ans)
                ans = area;
        }
        stack[++top] = i;
    }
    free(stack);
    return ans;
}
