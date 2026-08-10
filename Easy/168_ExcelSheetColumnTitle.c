# include <stdio.h>

char* convertToTitle(int columnNumber) {
    char* ans = (char*)calloc(20, sizeof(char));
    int idx = 0;

    while (columnNumber > 0) {
        columnNumber--;
        ans[idx++] = columnNumber % 26 + 'A';
        columnNumber = columnNumber / 26;
    }

    int head = 0; int tail = idx - 1;
    while (head < tail) {
        char temp = ans[head];
        ans[head] = ans[tail];
        ans[tail] = temp;
        head++;
        tail--;
    }

    return ans;
}