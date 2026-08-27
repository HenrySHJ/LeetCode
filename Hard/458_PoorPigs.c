# include <stdio.h>
# include <stdlib.h>

int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
    // Each pig represents bit 
    // Use dead pig bit as rounds find buckets
    int n = minutesToTest / minutesToDie;

    int T = 1;
    int ans = 0;
    while (T < buckets) {
        T *= n + 1;
        ans++;
    }
    return ans;
}