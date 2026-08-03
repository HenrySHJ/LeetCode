# include <stdio.h>
# include <stdlib.h>
# include <string.h>

bool wordBreak(char* s, char** wordDict, int wordDictSize) {
    // Initialize dp table
    int lenS = strlen(s);
    bool* dp = (bool*)calloc((lenS + 1), sizeof(bool));
    dp[0] = true;

    // Topological order : from lowest s index check every word
    for (int i = 1; i < lenS + 1; i++) {
        for (int j = 0; j < wordDictSize; j++) {
            int lenW = strlen(wordDict[j]);

            int start = i - lenW;
            if (start >= 0 && dp[start] && strncmp(s + start, wordDict[j], lenW) == 0) {
                dp[i] = true;
                break;
            }
        }
    }

    if (dp[lenS]) return true;
    return false;
}