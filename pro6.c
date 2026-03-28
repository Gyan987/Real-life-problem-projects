// Problem Statement
// In a school, a tournament is being organized where N students participate. Each student has a skill level represented by an integer. The tournament is organized such that:

// In each round, students are paired to compete. Only pairs with skill difference ≤ K are allowed.

// If a student can’t be paired in a round, they are eliminated.

// From each valid pair, only the student with higher skill advances to the next round. If their skills are equal, the student with the lower index proceeds.

// The process continues until less than 2 students remain, i.e., the tournament cannot form even a single pair.

// You must determine:

// The total number of rounds played.

// The winner’s skill level, or -1 if no winner (i.e., no student survives after pairing rounds).


// Solution

#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}

// User logic function
void findWinnerAndRounds(int N, int K, int* skillLevels, int* rounds, int* winnerSkill) {

    int *current = skillLevels;
    int size = N;
    *rounds = 0;

    while(size >= 2){

        qsort(current, size, sizeof(int), cmp);

        int *next = (int*)malloc(size * sizeof(int));
        int nextSize = 0;

        for(int i = 0; i < size-1; ){

            if(current[i+1] - current[i] <= K){
                next[nextSize++] = current[i+1]; // higher skill advances
                i += 2;
            }
            else{
                i++;
            }
        }

        if(nextSize == 0){
            free(next);
            break;
        }

        (*rounds)++;

        current = next;
        size = nextSize;
    }

    if(size == 1){
        *winnerSkill = current[0];
    }
    else{
        *winnerSkill = -1;
    }
}

int main() {

    int N, K;
    scanf("%d %d", &N, &K);

    int* skillLevels = (int*)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++){
        scanf("%d", &skillLevels[i]);
    }

    int rounds, winnerSkill;

    findWinnerAndRounds(N, K, skillLevels, &rounds, &winnerSkill);

    printf("%d %d\n", rounds, winnerSkill);

    free(skillLevels);

    return 0;
}