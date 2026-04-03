// Problem Statement
// Alex is a game developer designing a puzzle game for his players. In the game, there's a treasure hunt that takes place across multiple levels. Each level has a grid of treasures, and Alex wants to find the optimal path for the player to collect the treasure in the shortest possible way.
// Each level consists of an `N x N` grid where each cell contains a certain amount of treasure. The player can start collecting treasures from any cell in the first row and, in each subsequent row, they must select one treasure while avoiding the column from which they collected treasure in the previous row (no direct vertical shifts allowed). The goal is to calculate the minimum sum of treasures collected along such a valid path.


// solution


#include <stdio.h>
#include <limits.h>
#include <string.h>

// Helper: access 2D VLA passed as int**
#define G(i,j) (((int (*)[n])grid)[i][j])

int min_treasure(int** grid, int n) {
    // dp[j] = min sum to reach current row at column j
    int dp[n], ndp[n];

    // Initialize with first row
    for (int j = 0; j < n; j++)
        dp[j] = G(0, j);

    for (int i = 1; i < n; i++) {
        // Find the two smallest values in dp[] and their columns
        int min1 = INT_MAX, min2 = INT_MAX;
        int min1_col = -1;

        for (int j = 0; j < n; j++) {
            if (dp[j] < min1) {
                min2 = min1;
                min1 = dp[j]; min1_col = j;
            } else if (dp[j] < min2) {
                min2 = dp[j];
            }
        }

        // Build next row DP
        for (int j = 0; j < n; j++) {
            // Can't come from same column j
            int best_prev = (j != min1_col) ? min1 : min2;
            ndp[j] = best_prev + G(i, j);
        }

        // Copy ndp -> dp
        memcpy(dp, ndp, sizeof(int) * n);
    }

    // Answer = minimum across last row
    int result = INT_MAX;
    for (int j = 0; j < n; j++)
        if (dp[j] < result) result = dp[j];

    return result;
}

int main() {
    int n;
    scanf("%d", &n);

    int grid[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &grid[i][j]);

    printf("%d\n", min_treasure((int**)grid, n));
    return 0;
}