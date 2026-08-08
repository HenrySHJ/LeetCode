# include <stdio.h>
# include <string.h>
# include <stdbool.h>

bool isPalindrome(char* s) {
    int n = strlen(s);
    int i = 0;
    int j = n - 1;

    while (i < j) {
        while (i < j && !((s[i] >= 'A' && s[i] <= 'Z') || 
                          (s[i] >= 'a' && s[i] <= 'z') || 
                          (s[i] >= '0' && s[i] <= '9'))) {
            i++;
        }

        while (i < j && !((s[j] >= 'A' && s[j] <= 'Z') || 
                          (s[j] >= 'a' && s[j] <= 'z') || 
                          (s[j] >= '0' && s[j] <= '9'))) {
            j--;
        }

        int p1, p2;
        if (s[i] >= 'A' && s[i] <= 'Z')
            p1 = s[i] - 'A';
        else 
            p1 = s[i] - 'a';

        if (s[j] >= 'A' && s[j] <= 'Z')
            p2 = s[j] - 'A';
        else 
            p2 = s[j] - 'a';

        if (p1 != p2)
            return false;
        i++;
        j--;
    }    
    return true;
}
