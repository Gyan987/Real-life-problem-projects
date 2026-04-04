// Problem Statement
// In the kingdom of Numerica, there was an ancient relic known as the Crystal of Balance, hidden deep within the royal treasury. The relic was said to hold the power to bring prosperity or ruin, depending on the wisdom of the one who unlocked its secrets.

// The relic's magic could only be activated by solving a unique puzzle engraved on its surface. The puzzle read:

// "Divide the crystal’s four-digit magical code into two equal parts of two digits each, such that their combined energy—their product—is minimized. Only then will the crystal's true power reveal itself."

// The task seemed simple, but every wrong attempt risked disaster. With no zeros in the code, you, the smartest guy in the kingdom took the challenge to activate the magic.

// soluton


#include <stdio.h>
#include <limits.h>

int minimum_product(int N) {
    int digits[4];
    digits[0] = (N / 1000) % 10;
    digits[1] = (N / 100)  % 10;
    digits[2] = (N / 10)   % 10;
    digits[3] =  N         % 10;

    int min_prod = INT_MAX;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (j == i) continue;
            for (int k = 0; k < 4; k++) {
                if (k == i || k == j) continue;
                for (int l = 0; l < 4; l++) {
                    if (l == i || l == j || l == k) continue;

                    // Permutation: digits[i], digits[j], digits[k], digits[l]
                    int A = digits[i] * 10 + digits[j];  // first  2-digit number
                    int B = digits[k] * 10 + digits[l];  // second 2-digit number

                    int prod = A * B;
                    if (prod < min_prod) min_prod = prod;
                }
            }
        }
    }

    return min_prod;
}

int main() {
    int N;
    scanf("%d", &N);
    printf("%d\n", minimum_product(N));
    return 0;
}