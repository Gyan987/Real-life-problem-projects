// Problem Statement
// Rahul has a unit test in school, but he woke up very late in the morning. He has to go to school as soon as possible. Rahul's house is situated at 0,0 index of integer matrix and his school is at n-1, m-1 index of the matrix. You have to help Rahul to find the shortest route.

// You are provided with a matrix, in which the ith, jth value represents distance.

// Input Format
// The first line of input should contain a single integer n -  representing a row of matrix.
// The second line of input should contain a single integer m -  representing column of matrix.
// The next line n lines contain m number each, jth number in ith line denotes the number that is written on cell arr[i][j].
// Output Format
// The output should be a single integer value.

// solution

#include <stdio.h>
#include <stdlib.h>

int min(int a, int b){
    return a < b ? a : b;
}

int userLogic(int **grid, int n, int m) {

    int **dp = (int**)malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++){
        dp[i] = (int*)malloc(m * sizeof(int));
    }

    dp[0][0] = grid[0][0];

    // first row
    for(int j = 1; j < m; j++){
        dp[0][j] = dp[0][j-1] + grid[0][j];
    }

    // first column
    for(int i = 1; i < n; i++){
        dp[i][0] = dp[i-1][0] + grid[i][0];
    }

    // fill rest
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
        }
    }

    int result = dp[n-1][m-1];

    for(int i = 0; i < n; i++){
        free(dp[i]);
    }
    free(dp);

    return result;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int **grid = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        grid[i] = (int *)malloc(m * sizeof(int));
        for (int j = 0; j < m; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    int result = userLogic(grid, n, m);
    printf("%d\n", result);

    for (int i = 0; i < n; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}
