# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

bool lemonadeChange(int* bills, int billsSize) {
    int count[2] = {0};
    for (int i = 0; i < billsSize; i++) {
        // $5
        if (bills[i] == 5)
            count[0]++;
        // $10
        else if (bills[i] == 10) {
            if (count[0] == 0)
                return false;
            else {
                count[0]--;
                count[1]++;
            }
        }
        // $20
        else {
            int exc = 20;
            while (exc > 10 && count[1] > 0) {
                count[1]--;
                exc -= 10;
            }
            while (exc > 5 && count[0] > 0) {
                count[0]--;
                exc -= 5;
            }

            if (exc > 5) return false;    
        }
    }
    return true;
}