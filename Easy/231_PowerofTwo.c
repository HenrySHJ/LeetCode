# include <stdio.h>
# include <stdbool.h>

bool isPowerOfTwo(int n) {
    int count32 = __builtin_popcount(n);
    if (n > 0 && count32 == 1)
        return true;
    return false;    
}