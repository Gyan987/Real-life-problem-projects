// Problem Statement
// One day, Mary wanted to give a present to her friend. She decided on a beautiful bouquet of flowers and began collecting them. She needed precisely 2 types of flowers, and the total number of flowers required was 't'. To gather these, she started picking from her garden, which contained 'N' types of flowers. Each type was arranged in a queue in non-decreasing order, such as 1, 3, 6, 15, and so forth.

// Now, she seeks your help in determining the indexes of the flowers she should collect.

// Note: For every case, there will always be a pair of flowers whose sum equals 't'. If multiple pairs exist, select the first occurrence.


// Solution:

#include <stdio.h>

void find_flower_indices(int n, int t, int arr[], int result[2]) {

    int left = 0;
    int right = n - 1;

    while (left < right) {

        int sum = arr[left] + arr[right];

        if (sum == t) {
            result[0] = left;
            result[1] = right;
            return;
        }
        else if (sum < t) {
            left++;
        }
        else {
            right--;
        }
    }
}

int main() {
    int n, t;

    scanf("%d %d", &n, &t);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result[2];

    find_flower_indices(n, t, arr, result);

    printf("%d %d", result[0], result[1]);

    return 0;
}