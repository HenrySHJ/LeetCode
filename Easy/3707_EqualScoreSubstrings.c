# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

bool scoreBalance(char* s) {
    int n = strlen(s);
    int prefix[n];
    prefix[0] = s[0] - 'a' + 1;

    for (int i = 1; i < n; i++) 
        prefix[i] = prefix[i - 1] + s[i] - 'a' + 1;
    
    for (int i = 0; i < n - 1; i++) {
        if (prefix[i] == prefix[n - 1] - prefix[i])
            return true;
    }

    return false;
}
