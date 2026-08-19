# include <stdio.h>
# include <stdlib.h>

int compare(const void* a, const void* b) {
    int* rowA = *(int**)a;
    int* rowB = *(int**)b;
    return rowA[0] - rowB[0];
}

int maxNumberOfFamilies(int n, int** reservedSeats, int reservedSeatsSize, int* reservedSeatsColSize) {
    qsort(reservedSeats, reservedSeatsSize, sizeof(int*), compare);

    int reservedRowsCount = 0; 
    int ans = 0;

    int i = 0;
    while (i < reservedSeatsSize) {
        int row = reservedSeats[i][0];
        int bitmask = 0; 

        while (i < reservedSeatsSize && reservedSeats[i][0] == row) {
            int col = reservedSeats[i][1];
            bitmask |= (1 << (col - 1));
            i++;
        }

        reservedRowsCount++;

        // Check bit (0b0111100000 = 480, 0b0001111000 = 120, 0b0000011110 = 30)
        bool left = (bitmask & 480) == 0;    
        bool middle = (bitmask & 120) == 0;  
        bool right = (bitmask & 30) == 0;   

        if (left && right) 
            ans += 2;
        else if (left || middle || right) 
            ans += 1;
    }

    ans += (n - reservedRowsCount) * 2;

    return ans;
}