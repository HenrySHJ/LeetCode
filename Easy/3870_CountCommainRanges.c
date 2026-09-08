# include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int countCommas(int n) {
    return max(0, n - 1000 + 1);
}