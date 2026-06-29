# include <stdio.h>
# include <stdlib.h>

// 1. n - k <= x <= n + k
// 2. n & x == 0
int max(int a, int b) {
    if (a <= b) return b;
    else return a;
}

int sumOfGoodIntegers(int n, int k) {
    int output = 0;
    for (int x = max(0, n - k); x <= n + k; x++) {
        if ((abs(n - x) <= k) && ((n & x) == 0)) output += x;
    }
    return output;
}