# include <stdio.h>
# include <string.h>

int lengthOfLongestSubstring(char* s) {
    int length = strlen(s);

    int lastIndex[128];
    for (int i = 0; i < 128; i++) {
        lastIndex[i] = -1;
    }

    int left = 0;
    int right = 0;
    int max = 0;
    for (int right = 0; right < length; right++) {
        char cur = s[right];

        if (lastIndex[cur] >= left) {
            left = lastIndex[cur] + 1;
        }

        lastIndex[cur] = right;
        if (max <= right - left + 1) {
            max = right - left + 1;
        }
    }
    return max;
}