// Problem Statement
// Given a 0-indexed integer array nums and an integer K, you need to find the total number of pairs (i, j) such that 0 <= i < j < n and the bitwise XOR of nums[i] and nums[j] is strictly greater than k. 

// Return the total count of such valid pairs.

// Input Format
// The first line contains an value N which represents as the size of the array.

// The second line contains N space-separated integers representing the elements of the array nums.

// The third line contains an value K which represents as the target XOR threshold.

// Output Format
// The output contains a single integer representing the total count of valid pairs.


// solution    


#include <stdio.h>

int main() {

    int N;
    scanf("%d", &N);

    int nums[N];
    for(int i = 0; i < N; i++){
        scanf("%d", &nums[i]);
    }

    int K;
    scanf("%d", &K);

    long long count = 0;

    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            if((nums[i] ^ nums[j]) > K){
                count++;
            }
        }
    }

    printf("%lld\n", count);

    return 0;
}