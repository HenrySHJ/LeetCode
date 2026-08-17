# include <stdio.h>
# include <stdbool.h>

bool isAnagram(char* s, char* t) {
    int freq[26] = {0};

    int m = strlen(s);
    int n = strlen(t);

    if (m != n)
        return false;

    for (int i = 0; i < m; i++) 
        freq[s[i] - 'a']++;
    
    for (int i = 0; i < n; i++) {
        if (freq[t[i] - 'a'] == 0)
            return false;

        freq[t[i] - 'a']--;
    }

    return true;
}
