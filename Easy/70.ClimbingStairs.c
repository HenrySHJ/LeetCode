# include <stdio.h>

int climbStairs(int n) {
    int climb[n + 1] = {};
    if (n >= 1) climb[1] = 1;
    if (n >= 2) climb[2] = 2;
    for (int i = 3; i < n + 1; i++) {
        climb[i] = climb[i - 1] + climb[i - 2];
    }
    return climb[n];
}