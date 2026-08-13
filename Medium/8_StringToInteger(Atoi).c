# include <stdio.h>
# include <string.h>
# include <stdbool.h>
# include <limits.h>

int myAtoi(char* s) {
    int i = 0;
    int sign = 1;
    long long ans = 0;

    while (s[i] == ' ') {
        i++;
    }

    if (s[i] == '+' || s[i] == '-') {
        if (s[i] == '-') {
            sign = -1;
        }
        i++;
    }

    while (s[i] >= '0' && s[i] <= '9') {
        ans = ans * 10 + (s[i] - '0');

        if (sign == 1 && ans >= INT_MAX) {
            return INT_MAX;
        }
        if (sign == -1 && -ans <= INT_MIN) {
            return INT_MIN;
        }

        i++;
    }

    return (int)(ans * sign);
}