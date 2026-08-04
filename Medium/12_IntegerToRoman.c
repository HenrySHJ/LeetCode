# include <stdio.h>
# include <stdlib.h>
# include <string.h>

char hash(int num) {
    if (num == 1000)
        return 'M';
    else if (num == 500)
        return 'D';
    else if (num == 100)
        return 'C';
    else if (num == 50)
        return 'L';
    else if (num == 10)
        return 'X';
    else if (num == 5)
        return 'V';
    else if (num == 1)
        return 'I';
    else 
        return ' ';
}

char* intToRoman(int num) {
    int capacity = 2000;
    char* ans = (char*)malloc(capacity * sizeof(char));
    int index = 0;

    int mod = 1000;

    while (num > 0) {
        // Getting the highest digit
        int n = num / mod;
        
        if (n == 4) {
            ans[index++] = hash(mod);
            ans[index++] = hash(mod * 5);
        }
        else if (n == 9) {
            ans[index++] = hash(mod);
            ans[index++] = hash(mod * 10);
        }
        else {
            if (n >= 5) {
                ans[index++] = hash(mod * 5);
                n -= 5;
            }
            while (n--) {
                ans[index++] = hash(mod);
            }
        }

        // Move to lower digit
        num = num % mod;
        mod /= 10;
    }
    ans[index] = '\0';
    return ans;
}