# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
    int cx = max(x1, min(xCenter, x2));
    int cy = max(y1, min(yCenter, y2));

    int dx = xCenter - cx;
    int dy = yCenter - cy;

    return dx * dx + dy * dy <= radius * radius;
}
