// Problem Statement
// Ravi discovered that some strings read the same forwards and backwards, which are called palindromes.

// He noticed that every string he encountered has at least one palindromic substring. He wants to know how to find the longest palindromic substring in a given string, S.

// Can you help him determine the length of this longest palindromic substring?


// solution:


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b){
    return a > b ? a : b;
}

int expand(char *s, int left, int right, int n){
    while(left >= 0 && right < n && s[left] == s[right]){
        left--;
        right++;
    }
    return right - left - 1;
}

int longest_palindromic_substring_length(int n, char* s) {
    
    int maxLen = 1;

    for(int i = 0; i < n; i++){

        int len1 = expand(s, i, i, n);     // odd palindrome
        int len2 = expand(s, i, i+1, n);   // even palindrome

        maxLen = max(maxLen, max(len1, len2));
    }

    return maxLen;
}

int main() {
    int n;
    char s[1001];
    
    scanf("%d", &n);
    scanf("%s", s);
    
    int result = longest_palindromic_substring_length(n, s);
    printf("%d\n", result);
    
    return 0;
}