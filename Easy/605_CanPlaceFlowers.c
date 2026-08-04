# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    for (int i = 0; i < flowerbedSize; i++) {
        if (flowerbed[i] == 1)
            continue;

        if (i - 1 >= 0 && flowerbed[i - 1] == 1)
            continue;

        if (i + 1 <= flowerbedSize - 1 && flowerbed[i + 1] == 1)
            continue;
        
        n--;
        i++;
    }

    if (n <= 0) 
        return true;
    return false;
}