# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

bool sumGame(char* num) {
    int n = strlen(num);
    int m = n / 2;

    int sum1 = 0;
    int sum2 = 0;
    int qcount1 = 0;
    int qcount2 = 0;
    for (int i = 0; i < m; i++) {
        if (num[i] != '?') 
            sum1 += num[i] - '0';
        else
            qcount1++;
    }

    for (int i = m; i < n; i++) {
        if (num[i] != '?') 
            sum2 += num[i] - '0';
        else
            qcount2++;
    }

    int sum_diff = sum1 - sum2;
    int q_diff = qcount1 - qcount2;

    if ((qcount1 + qcount2) % 2 != 0) 
        return true;

    if (sum_diff + (q_diff / 2) * 9 == 0) 
        return false; 

    return true;
}
