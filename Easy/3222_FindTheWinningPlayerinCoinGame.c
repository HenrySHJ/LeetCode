# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

char* winningPlayer(int x, int y) {
    int count = 0;

    while (x >= 1 && y >= 4) {
        x--;
        y -= 4;
        count++;
    }

    if (count % 2 == 0)
        return "Bob";
    return "Alice";
}