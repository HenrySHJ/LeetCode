# include <stdio.h>
# include <stdlib.h>

int passThePillow(int n, int time) {
    time = time % (n * 2 - 2);
    if (n > time)
        return 1 + time;
    else
        return n * 2 - time - 1;
}