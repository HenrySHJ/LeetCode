# include <stdio.h>

long long max(long long a, long long b) {
    return (a > b) ? a : b;
}

int maxRotateFunction(int* nums, int numsSize) {
    long long n = numsSize;
    long long sum = 0;
    long long f = 0;

    for (int i = 0; i < n; i++) {
        sum += nums[i];
        f += (long long)i * nums[i];
    }

    long long ans = f;

    for (int k = 1; k < n; k++) {
        f = f + sum - n * nums[n - k];
        ans = max(ans, f);
    }

    return (int)ans;
}
