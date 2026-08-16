# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

bool stoneGameIX(int* stones, int stonesSize) {
    int count[3] = {0};
    for (int i = 0; i < stonesSize; i++) 
        count[stones[i] % 3]++;
    
    if (count[0] % 2 == 0)
        return count[1] != 0 && count[2] != 0;

    return abs(count[2] - count[1]) >= 3;
}
