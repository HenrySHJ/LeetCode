# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int max(int a, int b ) {
    if (a < b) return b;
    else return a;
}

char* addBinary(char* a, char* b) {
    int i = strlen(a) - 1;
    int j = strlen(b) - 1;

    int len = ((i > j) ? i : j) + 2;

    char* ans = (char*)malloc((len + 1) * sizeof(char));
    ans[len] = '\0';

    int k = len - 1;
    int carry = 0;
    
    while (i >= 0 || j >= 0 || carry > 0) {
        int sum = carry;
        
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        
        ans[k--] = (sum & 1) + '0';
        
        carry = sum >> 1;
    }

    if (k == 0) {
        memmove(ans, ans + 1, len);
    }  

    return ans;
}
