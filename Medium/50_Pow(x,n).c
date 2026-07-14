# include <stdio.h>

double myPow(double x, int n) {
    long long num;
    if (n < 0) {
        x = 1 / x;
        num = (long long) n * -1;
    }
    
    else {
        num = (long long) n;
    }
    double ans = 1.00000;
    while (num != 0) {
        if ((num & 1) != 0) {
            ans *= x;
        }

        x *= x;
        num = num >> 1;
    }

    return ans;
}