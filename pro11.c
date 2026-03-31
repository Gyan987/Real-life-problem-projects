// Problem Statement
// You are given a string S of length N, consisting of lowercase English letters. Your task is to partition the string into the minimum number of palindromic substrings while also minimizing the cost of partitioning.

// The cost of partitioning is defined as the sum of ASCII values of the characters at both ends of each cut. If multiple ways exist to achieve the minimum number of palindromic partitions, select the one with the lowest cost.

// Return the minimum cost required to partition the string. If the string is already a palindrome, return 0.

// solution


#include <stdio.h>
#include <string.h>
#include <limits.h>

int min_partition_cost(const char* S) {
    int N = strlen(S);
    if (N <= 1) return 0;

    // Step 1: Precompute palindrome table
    int isPal[10001][10001 >> 6]; // huge memory if declared like this — we’ll use optimized approach below
    static char pal[10001][10001]; // For simplicity in clarity code example — optimize in real code.
    
    for (int i = 0; i < N; i++) {
        pal[i][i] = 1;
    }
    for (int i = 0; i < N - 1; i++) {
        pal[i][i + 1] = (S[i] == S[i + 1]);
    }
    for (int len = 3; len <= N; len++) {
        for (int i = 0; i + len - 1 < N; i++) {
            int j = i + len - 1;
            pal[i][j] = (S[i] == S[j]) && pal[i + 1][j - 1];
        }
    }

    // Step 2: DP for minimum cuts + cost
    int cuts[10001];
    int cost[10001];
    for (int i = 0; i < N; i++) {
        cuts[i] = INT_MAX;
        cost[i] = INT_MAX;
    }

    for (int i = 0; i < N; i++) {
        if (pal[0][i]) {
            cuts[i] = 0;
            cost[i] = 0;
        } else {
            for (int j = 0; j < i; j++) {
                if (pal[j + 1][i]) {
                    int newCuts = cuts[j] + 1;
                    int newCost = cost[j] + (int)S[j] + (int)S[j + 1];
                    if (newCuts < cuts[i] || (newCuts == cuts[i] && newCost < cost[i])) {
                        cuts[i] = newCuts;
                        cost[i] = newCost;
                    }
                }
            }
        }
    }

    return cost[N - 1];
}

int main() {
    char S[10001];
    if (fgets(S, sizeof(S), stdin) != NULL) {
        S[strcspn(S, "\n")] = '\0'; // Remove newline
    }
    int result = min_partition_cost(S);
    printf("%d\n", result);
    return 0;
}
