# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct pair {
    int first;
    int last;
} pair;

int compare(const void* a, const void* b) {
    pair* p1 = (pair*)a;
    pair* p2 = (pair*)b;
    return (p1->last > p2->last) - (p1->last < p2->last);
}

char** maxNumOfSubstrings(char* s, int* returnSize) {
    int n = strlen(s);

    int first[26];
    int last[26];
    for (int i = 0; i < 26; i++) {
        first[i] = -1;
        last[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        if (first[s[i] - 'a'] == -1) 
            first[s[i] - 'a'] = i;
        
        last[s[i] - 'a'] = i;
    }

    pair arr[26];
    int count = 0;

    int idx = 0;
    for (int i = 0; i < 26; i++) {
        if (first[i] == -1)
            continue;

        int l = first[i];
        int r = last[i];
        bool isValid = true;

        for (int j = l; j <= r; j++) {
            int charIdx = s[j] - 'a';
            
            if (first[charIdx] < l) {
                isValid = 0;
                break;
            }
            
            if (last[charIdx] > r) {
                r = last[charIdx];
            }
        }

        if (isValid) {
            arr[count].first = l;
            arr[count].last = r;
            count++;
        }
    }

    qsort(arr, count, sizeof(pair), compare);

    int subs = 0;
    char** ans = (char**)malloc(26 * sizeof(char*));

    bool* used = (bool*)calloc(n, sizeof(bool));
    for (int i = 0; i < count; i++) {
        bool flag = false;
        for (int j = arr[i].first; j <= arr[i].last; j++) {
            if (used[j]) {
                flag = true;
                break;
            }
        }

        if (flag)
            continue;

        ans[subs] = (char*)malloc((arr[i].last - arr[i].first + 2) * sizeof(char));
        for (int j = arr[i].first; j <= arr[i].last; j++) {
            used[j] = true;
            ans[subs][j - arr[i].first] = s[j];
        }
        ans[subs++][arr[i].last - arr[i].first + 1] = '\0';
    }

    free(used);
    *returnSize = subs;
    return ans;
}
