//
// Created by serhi on 12/22/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "master_mind.h"

void printGuess(int *guess) {
    printf("[ ");
    for (int i = 0; i < GUESSNUMBERS; i++) {
        printf("%d ", guess[i]);
    }
    printf("] ");
}

int main() {
    int *allPosibilitiesList = allPosibilities();

    bool *validMask = malloc(TOTALPERMUTATIONS * sizeof(bool));
    for (int i = 0; i < TOTALPERMUTATIONS; i++) validMask[i] = true;

    int attempts = 1;
    int rightPlace, wrongPlace;

    printf("Think of a sequence of %d numbers (1-%d).\n", GUESSNUMBERS, GUESSRANGE);
    printf("I will try to guess it.\n");
    printf("------------------------------------------------------------------\n");

    while (true) {
        int guessIndex = -1;
        for (int i = 0; i < TOTALPERMUTATIONS; i++) {
            if (validMask[i]) {
                guessIndex = i;
                break; // Found a valid guess
            }
        }

        if (guessIndex == -1) {
            printf("Error: No valid possibilities left. You might have entered incorrect feedback previously.\n");
            break;
        }

        int *currentGuess = &allPosibilitiesList[guessIndex * GUESSNUMBERS];

        printf("Attempt %d: I guess ", attempts);
        printGuess(currentGuess);
        printf("\n");

        printf("On right place: ");
        scanf("%d", &rightPlace);
        printf("On wrong place: ");
        scanf("%d", &wrongPlace);


        if (rightPlace == GUESSNUMBERS) {
            printf("I guessed it in %d attempts!\n", attempts);
            break;
        }

        filterList(allPosibilitiesList, validMask, currentGuess, rightPlace, wrongPlace);

        int remaining = 0;
        for (int i = 0; i < TOTALPERMUTATIONS; i++) if (validMask[i]) remaining++;
        printf("Possible codes remaining: %d\n\n", remaining);

        attempts++;
    }

    free(allPosibilitiesList);
    free(validMask);

    return 0;
}
