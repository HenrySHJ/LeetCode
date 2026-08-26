# include <stdio.h>
# include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int leastInterval(char* tasks, int tasksSize, int n) {
    int freq[26] = {0};
    int max_freq = 0;

    // Filling freq and find max_freq
    for (int i = 0; i < tasksSize; i++) {
        freq[tasks[i] - 'A']++;
        if (freq[tasks[i] - 'A'] > max_freq) {
            max_freq = freq[tasks[i] - 'A'];
        }
    }

    // Finding the count of max_freq
    int count = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] == max_freq) 
            count++;
    }

    int ans = (max_freq - 1) * (n + 1) + count;

    return max(tasksSize, ans);
}