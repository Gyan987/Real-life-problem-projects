// Problem Statement
// John was learning about arrays when his friend Ram arrived. Seeing John, Ram thought of a challenge for him. He challenged John to calculate the "measurement" of an array a of size n.
// Given a 0-indexed array, Ram defined the measurement of the array as the sum of the "sanities" of all the elements in the array. To calculate the sanity of each element in the array, the following operations need to be performed:

// Sort the given array.
// Calculate the sanity of an element in the array, which is defined as the sum of its original index (before sorting) and the index of its last occurrence in the new array (after sorting).
// Your task is to help John calculate the measurement of the array. Since the output may be too large, print it modulo 10^9+7.

// Note that duplicate elements may exist in the array.

// Solution

#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int cmp(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}

int user_logic(int n, int arr[]) {

    int *sorted = (int*)malloc(n * sizeof(int));

    for(int i=0;i<n;i++)
        sorted[i] = arr[i];

    qsort(sorted, n, sizeof(int), cmp);

    int *last = (int*)malloc((1000001) * sizeof(int));

    for(int i=0;i<=1000000;i++)
        last[i] = -1;

    for(int i=0;i<n;i++)
        last[sorted[i]] = i;

    long long ans = 0;

    for(int i=0;i<n;i++){
        ans = (ans + i + last[arr[i]]) % MOD;
    }

    free(sorted);
    free(last);

    return (int)ans;
}

int main() {

    int n;
    scanf("%d",&n);

    int arr[n];

    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    int measurement = user_logic(n, arr);

    printf("%d\n",measurement);

    return 0;
}