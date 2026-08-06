# include <stdio.h>
# include <string.h>

int max(int a, int b, int c) {
    if (a > b && a > c)
        return a;
    else if (b > c)
        return b;
    else
        return c;
}

int findMinimumOperations(char* s1, char* s2, char* s3) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int len3 = strlen(s3);

    int minlen = 0;
    int maxlen = max(len1, len2, len3);
    for (int i = 0; i < maxlen; i++) {
        if (s1[i] == s2[i] && s2[i] == s3[i]) 
            minlen++;
        else
            break;
    }

    if (minlen == 0) 
        return -1;
    return len1 + len2 + len3 - minlen * 3;
}