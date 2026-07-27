# include <stdio.h>
# include <stdlib.h>

int dfs(int bitmask, int cur, int n) {
    // bitmask : 1 if number is used 0 if not used
    // cur : filling bit backwards
    if (cur == 0)
        return 1;

    int sum = 0;
    for (int i = 0; i < n; i++) {
        // i already used in bit
        if (bitmask & (1 << i))
            continue;

        // Checking divisible condition
        if ((i + 1) % cur == 0 || cur % (i + 1) == 0) 
            sum += dfs(bitmask ^ 1 << i, cur - 1, n);
    }
    return sum;
}

int countArrangement(int n) {
    return dfs(0, n, n);
}