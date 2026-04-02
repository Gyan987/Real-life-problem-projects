// Problem Statement
// In a futuristic world, humans have discovered a method to alter their genetic structure using nanotechnology. This technology allows individuals to enhance their physical abilities, but with each enhancement, there is a trade-off. The "Genetic Alteration" is represented by a number, which corresponds to the total number of genetic modifications an individual has undergone.

// The process of enhancing one's genetic structure is governed by a series of operations that can be performed on the initial genetic value. Specifically, the value of the "Genetic Alteration" can be reduced by dividing it by 2, 3, or 4 in each operation. This process can be repeated as many times as needed.

// Once the alterations reach a certain level, the individual can choose to finalize their enhancements and "unlock" a new level of physical ability, represented by a final value of the genetic alteration.

// The goal is to maximize the physical ability enhancement level by performing the available operations and then finalizing the genetic alteration.

// Task:

// Given an initial genetic alteration value N, find out the maximum possible physical ability enhancement level that can be achieved through this process.

// solution;


#include <stdio.h>
#include <stdlib.h>

int Maximum(int N) {
    // Allocate dp array — dp[i] = max enhancement for value i
    int *dp = (int *)malloc((N + 1) * sizeof(int));
    
    // Base cases
    dp[0] = 0;
    if (N == 0) {
        free(dp);
        return 0;
    }
    dp[1] = 1;  // 1 can't be split further usefully (1/2=1/3=1/4=0)

    for (int i = 2; i <= N; i++) {
        // Option 1: keep i as-is
        // Option 2: split into i/2 + i/3 + i/4 (integer division)
        int split = dp[i/2] + dp[i/3] + dp[i/4];
        dp[i] = (split > i) ? split : i;
    }

    int result = dp[N];
    free(dp);
    return result;
}

int main() {
    int N;
    scanf("%d", &N);

    int result = Maximum(N);
    printf("%d\n", result);

    return 0;
}