# include <stdio.h>
# include <stdbool.h>

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int start = 0;
    int end = matrixSize - 1;
    int mid = (start + end) / 2;

    while (start <= end) {
        mid = (start + end) / 2;
        if (matrix[mid][0] <= target)
            start = mid + 1;
        else
            end = mid - 1;
    }

    if (matrix[mid][0] > target && mid > 0) 
        mid--; 

    int row = mid;
    start = 0;
    end = matrixColSize[row] - 1;
    mid = (start + end) / 2;

    while (start <= end) {
        mid = (start + end) / 2;
        if (matrix[row][mid] == target)
            return true;
        else if (matrix[row][mid] <= target)
            start = mid + 1;
        else
            end = mid - 1;
    }    
    return false;
}