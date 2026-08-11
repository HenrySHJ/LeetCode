// First Solution : Sort by points and dp by descending order : 16ms
# include <stdio.h>
# include <stdlib.h>

typedef struct Tuple {
    int num;
    int x;
    int y;
} Tuple;

int max(int a, int b) {
    return (a < b) ? b : a;
}

int compare(const void* a, const void* b) {
    const Tuple* t1 = (const Tuple*)a;
    const Tuple* t2 = (const Tuple*)b;
    return (t1->num < t2->num) - (t1->num > t2->num);
}

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1 ,0};

int longestIncreasingPath(int** matrix, int matrixSize, int* matrixColSize) {
    int m = matrixSize;
    int n = matrixColSize[0];

    // Tuple : {num, x, y} and sort by descending order
    Tuple grid[m * n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) 
            grid[i * n + j] = (Tuple){matrix[i][j], i, j};
    }    
    qsort(grid, m * n, sizeof(Tuple), compare);

    // Initialize dp table
    int dp[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            dp[i][j] = 1;
    }

    // Topological order by descending num
    for (int i = 0; i < m * n; i++) {
        Tuple cur = grid[i];
        int x = cur.x;
        int y = cur.y;

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            // Checking valid index
            if ((0 <= nx && nx < m) && (0 <= ny && ny < n)) {
                if (matrix[nx][ny] > matrix[x][y]) {
                    dp[x][y] = max(dp[x][y], dp[nx][ny] + 1);
                }
            }
        }
    }

    int ans = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) 
            ans = max(ans, dp[i][j]);
    }

    return ans;
}



// Second Solution : DFS + Memoization : 3ms
# include <stdio.h>
# include <stdlib.h>

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int max(int a, int b) {
    return (a < b) ? b : a;
}

int dfs(int** matrix, int m, int n, int x, int y, int** dp) {
    // Memoization
    if (dp[x][y] != 0) {
        return dp[x][y];
    }

    dp[x][y] = 1;

    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];

        if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
            if (matrix[nx][ny] > matrix[x][y]) {
                dp[x][y] = max(dp[x][y], 1 + dfs(matrix, m, n, nx, ny, dp));
            }
        }
    }

    return dp[x][y];
}

int longestIncreasingPath(int** matrix, int matrixSize, int* matrixColSize) {
    int m = matrixSize;
    int n = matrixColSize[0];

    // Initialize dp table
    int** dp = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        dp[i] = (int*)calloc(n, sizeof(int));
    }

    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            ans = max(ans, dfs(matrix, m, n, i, j, dp));
        }
    }

    // Free Memory
    for (int i = 0; i < m; i++) free(dp[i]);
    free(dp);

    return ans;
}