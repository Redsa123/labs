//
// Created by serhi on 12/31/2025.
//
#include <stdlib.h>
#include "master_mind.h"
#include <math.h>
#include <stdio.h>
#include <stdbool.h>

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

void calculateMatches(const int *candidate, const int *guess, int *tempResult) {
    int rightPlace = 0;
    int wrongPlace = 0;

    int *candidateFreq = calloc(GUESSRANGE + 1, sizeof(int));
    int *guessFreq = calloc(GUESSRANGE + 1, sizeof(int));

    for (int i = 0; i < GUESSNUMBERS; i++) {
        if (candidate[i] == guess[i]) {
            rightPlace++;
        } else {
            candidateFreq[candidate[i]]++;
            guessFreq[guess[i]]++;
        }
    }

    for (int i = 1; i <= GUESSRANGE; i++) {
        wrongPlace += min(candidateFreq[i], guessFreq[i]);
    }

    tempResult[0] = rightPlace;
    tempResult[1] = wrongPlace;

    free(candidateFreq);
    free(guessFreq);
}

void filterList(int *allPosibilitiesList, bool *validMask, int *currentGuess, int userRightPlace, int userWrongPlace) {
    int tempResult[2];

    for(int i = 0; i < TOTALPERMUTATIONS; i++) {
        if(!validMask[i]) continue;

        int *candidate = &allPosibilitiesList[i * GUESSNUMBERS];

        calculateMatches(candidate, currentGuess, tempResult);

        if (tempResult[0] != userRightPlace || tempResult[1] != userWrongPlace) {
            validMask[i] = false;
        }
    }
}

void printGuess(int *guess) {
    printf("[ ");
    for (int i = 0; i < GUESSNUMBERS; i++) {
        printf("%d ", guess[i]);
    }
    printf("] ");
}