# include <stdio.h>

int maximum69Number (int num) {
    int mod = 10000;
    
    while (mod > 0) {
        if ((num / mod) % 10 == 6) {
            num += mod * 3;
            break; 
        }
        mod /= 10;
    }

    return num;
}