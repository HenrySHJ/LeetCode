# include <stdio.h>
# include <stdbool.h>
# include <string.h>

bool checkValidString(char* s) {
    int min_op = 0;
    int max_op = 0; 

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            min_op++;
            max_op++;
        } 
        else if (s[i] == ')') {
            min_op--;
            max_op--;
        } 
        else if (s[i] == '*') {
            min_op--; 
            max_op++;
        }

        if (max_op < 0)
            return false;

        if (min_op < 0) 
            min_op = 0;
        
    }

    return min_op == 0;
}