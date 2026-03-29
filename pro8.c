// Problem Statement
// A futuristic ATM doesn't just dispense cash. It uses smart algorithms to optimize note usage and minimize leftover change.

// The ATM has the following denominations of notes:
// ₹2000, ₹500, ₹200, ₹100, ₹50, ₹20, ₹10.

// Each denomination has a limited count (provided as input).

// You are given:

// The amount X a customer wants to withdraw.

// The availability of each denomination in the ATM.

// Your task is to determine the minimum number of notes needed to dispense the exact amount. If it is not possible to give the exact amount using the available notes, print -1.

// You must prioritize larger denominations first to minimize the number of notes, but you cannot use more than the available number of notes in any denomination.



// Solution


#include <stdio.h>

// Function to calculate minimum notes
int calculateMinimumNotes(int amount, int available[]) {

    int notes[7] = {2000, 500, 200, 100, 50, 20, 10};
    int totalNotes = 0;

    for(int i = 0; i < 7; i++) {

        int need = amount / notes[i];

        int use = need < available[i] ? need : available[i];

        amount -= use * notes[i];

        totalNotes += use;
    }

    if(amount != 0)
        return -1;

    return totalNotes;
}

int main() {

    int amount;
    int available[7];

    scanf("%d", &amount);

    for(int i = 0; i < 7; i++)
        scanf("%d", &available[i]);

    int result = calculateMinimumNotes(amount, available);

    printf("%d\n", result);

    return 0;
}