# include <stdio.h>
# include <stdlib.h>

typedef struct StackNode {
    int x;
    int y;
} StackNode;

int min(int a, int b) {
    if (a <= b) return a;
    else return b;
}

int trap(int* height, int heightSize) {
    StackNode stack[heightSize];
    int top = -1;
    int ans = 0;

    // Using stack
    for (int i = 0; i < heightSize; i++) {
        int lastHeight = 0;
        while (top != -1) {
            int curHeight;
            if (stack[top].y <= height[i]) {
                curHeight = stack[top].y;
                ans += (curHeight - lastHeight) * (i - stack[top].x - 1);
                lastHeight = curHeight;
                top--;
            }
            else {
                curHeight = height[i];
                ans += (curHeight - lastHeight) * (i - stack[top].x - 1);
                break;
            }
        }
        stack[++top] = (StackNode){i, height[i]}; 
    }

    return ans;
}