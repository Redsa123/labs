//
// Created by serhi on 12/31/2025.
//
#include <stdlib.h>
#include "master_mind.h"
#include <math.h>

void generateRecursive(int index, int *currentSequence, int *fullList, int *listCount) {
    if (index == GUESSNUMBERS) {
        for (int k = 0; k < GUESSNUMBERS; k++) {
            fullList[(*listCount * GUESSNUMBERS) + k] = currentSequence[k];
        }
        (*listCount)++;
        return;
    }

    for (int i = 1; i <= GUESSRANGE; i++) {
        currentSequence[index] = i;
        generateRecursive(index + 1, currentSequence, fullList, listCount);
    }
}

int *allPosibilities() {
    int *result = malloc(TOTALPERMUTATIONS * GUESSNUMBERS * sizeof(int));

    int *currentSequence = malloc(GUESSNUMBERS * sizeof(int));
    int listCount = 0;

    generateRecursive(0, currentSequence, result, &listCount);

    free(currentSequence);
    return result;
}

void calculateMatches(const int *secret, const int *guess, int *resultOut) {
    int rightPlace = 0;
    int wrongPlace = 0;

    int *secretFreq = calloc(GUESSRANGE + 1, sizeof(int));
    int *guessFreq = calloc(GUESSRANGE + 1, sizeof(int));

    for (int i = 0; i < GUESSNUMBERS; i++) {
        if (secret[i] == guess[i]) {
            rightPlace++;
        } else {
            secretFreq[secret[i]]++;
            guessFreq[guess[i]]++;
        }
    }

    for (int i = 1; i <= GUESSRANGE; i++) {
        wrongPlace += min(secretFreq[i], guessFreq[i]);
    }

    resultOut[0] = rightPlace;
    resultOut[1] = wrongPlace;

    free(secretFreq);
    free(guessFreq);
}

void filterList(int *allPermutations, bool *validMask, int *currentGuess, int userRightPlace, int userWrongPlace) {
    int tempResult[2];

    for(int i = 0; i < TOTALPERMUTATIONS; i++) {
        if(!validMask[i]) continue;

        int *candidate = &allPermutations[i * GUESSNUMBERS];

        calculateMatches(candidate, currentGuess, tempResult);

        if (tempResult[0] != userRightPlace || tempResult[1] != userWrongPlace) {
            validMask[i] = false;
        }
    }
}