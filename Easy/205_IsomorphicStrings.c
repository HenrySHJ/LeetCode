# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>

bool isIsomorphic(char* s, char* t) {
    int n = strlen(s);
    char matchS[128] = {0};
    char matchT[128] = {0};
    
    for (int i = 0; i < n; i++) {
        unsigned char sc = s[i];
        unsigned char tc = t[i];

        if (matchS[sc] != 0 || matchT[tc] != 0) {
            if (matchS[sc] != tc || matchT[tc] != sc) {
                return false;
            }
        } 
        else {
            matchS[sc] = tc;
            matchT[tc] = sc;
        }
    }
    
    return true;
}