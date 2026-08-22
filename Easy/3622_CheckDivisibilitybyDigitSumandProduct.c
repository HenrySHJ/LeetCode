# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

bool checkDivisibility(int n) {
    int original = n;
    int sum = 0;
    int product = 1;

    while (n > 0) {
        int r = n % 10;

        sum += r;
        product *= r;
        n /= 10;
    }

    if (original % (sum + product) == 0)
        return true;
    return false;
}
