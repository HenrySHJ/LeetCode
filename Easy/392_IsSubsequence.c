# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

bool isSubsequence(char* s, char* t) {
    int idx1 = 0;
    int length = strlen(s);

    for (int idx2 = 0; idx2 < strlen(t); idx2++)
        if (s[idx1] == t[idx2]) idx1++;
    
    if (idx1 == length) return true;
    else return false;
}