// Problem Statement
// You are given an array A of N positive integers. 

// A contiguous subarray A[l...r] (where l < r, meaning the length is at least 2) is called Dominant if the maximum element within this subarray is strictly greater than the sum of all other elements in the same subarray. 

// Mathematically, a subarray is Dominant if:
// 2 * max(A[k]) > sum(A[k]) for all k from l to r.

// Your task is to find the total number of Dominant subarrays in the given array A.


// solution

#include <stdio.h>

long long max(long long a,long long b){
    return a>b?a:b;
}

int main(){

    int N;
    scanf("%d",&N);

    long long A[N];
    for(int i=0;i<N;i++){
        scanf("%lld",&A[i]);
    }

    long long count=0;

    for(int l=0;l<N;l++){

        long long sum=A[l];
        long long mx=A[l];

        for(int r=l+1;r<N;r++){

            sum+=A[r];
            mx=max(mx,A[r]);

            if(2*mx>sum){
                count++;
            }
            else{
                break;
            }
        }
    }

    printf("%lld\n",count);

}