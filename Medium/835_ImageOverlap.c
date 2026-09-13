# include <stdio.h>
# include <stdlib.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int largestOverlap(int** img1, int img1Size, int* img1ColSize, int** img2, int img2Size, int* img2ColSize) {
    int m = img1Size;
    int n = img1ColSize[0];

    int arr[m * 2][n * 2];
    for (int i = 0; i < m * 2; i++) {
        for (int j = 0; j < n * 2; j++) 
            arr[i][j] = 0;
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                for (int l = 0; l < n; l++) {
                    if (img1[i][j] == 1 && img2[k][l] == 1) {
                        int dx = k - i;
                        int dy = l - j;
                        
                        arr[dx + m][dy + n]++;
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < m * 2; i++) {
        for (int j = 0; j < n * 2; j++) 
            ans = max(ans, arr[i][j]);
    }

    return ans;
}
