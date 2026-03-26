// Problem Statement
// In a town preparing for a festival, there are N houses arranged in a row, each with a certain happiness level H[i] if decorated.

// However, due to budget and aesthetics constraints, the town authority can decorate exactly K houses, and no two adjacent houses can be decorated (to prevent decoration clashes).

// Your task is to choose exactly K non-adjacent houses such that the total happiness is maximized.

// If it is not possible to decorate K non-adjacent houses, print -1.



solution:
#include <stdio.h>
#include <limits.h>

int max(int a, int b){
    return a > b ? a : b;
}

int calculateMaxHappiness(int N, int K, int* H) {

    if (K > (N + 1) / 2)
        return -1;

    int dp[N+1][K+1];

    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= K; j++){
            dp[i][j] = INT_MIN;
        }
    }

    for(int i = 0; i <= N; i++)
        dp[i][0] = 0;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= K; j++){

            dp[i][j] = dp[i-1][j];

            if(i >= 2 && dp[i-2][j-1] != INT_MIN){
                dp[i][j] = max(dp[i][j], dp[i-2][j-1] + H[i-1]);
            }
            else if(i == 1 && j == 1){
                dp[i][j] = max(dp[i][j], H[i-1]);
            }
        }
    }

    if(dp[N][K] == INT_MIN)
        return -1;

    return dp[N][K];
}

int main() {
    int N, K;

    scanf("%d %d", &N, &K);

    int H[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &H[i]);
    }

    int result = calculateMaxHappiness(N, K, H);

    printf("%d\n", result);

    return 0;
}