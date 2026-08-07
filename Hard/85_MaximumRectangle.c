# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int max(int a, int b) {
    if (a < b) return b;
    else return a;
}

int largestRectangleArea(int* heights, int n) {
    int* stack = (int*)malloc((n + 1) * sizeof(int));
    int top = -1;
    int max_area = 0;

    for (int i = 0; i <= n; i++) {
        int current_height = (i == n) ? 0 : heights[i];

        while (top >= 0 && heights[stack[top]] >= current_height) {
            int h = heights[stack[top--]];
            
            int width = (top == -1) ? i : (i - stack[top] - 1);
            
            int area = h * width;
            if (area > max_area) {
                max_area = area;
            }
        }

        stack[++top] = i;
    }

    free(stack);
    return max_area;
}

int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize) {
    int m = matrixSize;
    int n = matrixColSize[0];

    // Initialize height table
    int heights[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            heights[i][j] = 0;
    }
    
    // Set base case
    for (int j = 0; j < n; j++)
        heights[0][j] = matrix[0][j] - '0';

    // Filling height array
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == '1') {
                if (matrix[i - 1][j] == '1')
                    heights[i][j] = heights[i - 1][j] + 1;
                else 
                    heights[i][j] = 1;
            }
            else
                heights[i][j] = 0;
        }
    }

    int ans = 0;
    for (int i = 0; i < m; i++) {
        int area = largestRectangleArea(heights[i], n);
        if (area > ans) {
            ans = area;
        }
    }

    return ans;
}
