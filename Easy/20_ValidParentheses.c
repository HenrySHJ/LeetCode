# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>

bool isValid(char* s) {
    int length = strlen(s);

    if (length % 2 == 1) return false;
    
    char* check = (char*)malloc(sizeof(char) * length);
    int idx = 0;

    for (int i = 0; i < length; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            check[idx++] = s[i];
        }
        else {
            if (idx == 0) return false;
            else if (s[i] == ')') {
                if (check[idx - 1] == '(') idx--;
                else return false;
            }
            else if (s[i] == '}') {
                if (check[idx - 1] == '{') idx--;
                else return false;
            }
            else if (s[i] == ']') {
                if (check[idx - 1] == '[') idx--;
                else return false;
            }
        }
    }

    if (idx == 0) return true;
    else return false;
}