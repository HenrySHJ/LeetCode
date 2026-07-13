# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>

bool checkRecord(char* s) {
    int len = strlen(s);    
    int absent = 0;
    int late_streak = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == 'A') {
            absent++;
            late_streak = 0;
            if (absent == 2)
                return false;
        }
        else if (s[i] == 'L') {
            late_streak++;
            if (late_streak == 3)
                return false;
        }
        else {
            late_streak = 0;
        }
    }
    return true;
}