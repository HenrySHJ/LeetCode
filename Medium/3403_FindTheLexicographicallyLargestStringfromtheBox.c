# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int min(int a, int b) {
    return a < b ? a : b;
}

char* answerString(char* word, int numFriends) {
    if (numFriends == 1)
        return word;

    int n = strlen(word);
    char* ans = (char*)malloc((n + 1) * sizeof(char));
    for (int i = 0; i < n + 1; i++)
        ans[i] = ' ';

    for (int i = 0; i < n; i++) {
        int j = min(i + n - numFriends + 1, n);

        if (strncmp(ans, word + i, j - i) < 0) {
            strncpy(ans, word + i, j - i);
            ans[j - i] = '\0';
        }
    }
    return ans;
}