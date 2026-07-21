# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int strStr(char* haystack, char* needle) {
    int len1 = strlen(haystack);
    int len2 = strlen(needle);

    // strncmp(char* , char*, size)
    for (int i = 0; i < len1 - len2 + 1; i++) {
        if (strncmp(haystack + i, needle, len2) == 0) {
            return i;
        }
    }

    return -1;
}