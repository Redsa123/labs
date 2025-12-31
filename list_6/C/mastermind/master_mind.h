//
// Created by serhi on 12/31/2025.
//

#ifndef LABS_MASTER_MIND_H
#define LABS_MASTER_MIND_H

#define GUESSRANGE 6
#define GUESSNUMBERS 4
#define TOTALPERMUTATIONS ((int)pow(GUESSRANGE, GUESSNUMBERS))

#define max(a,b) \
({ __typeof__ (a) _a = (a); \
__typeof__ (b) _b = (b); \
_a > _b ? _a : _b; })

#define min(a,b) \
({__typeof__ (a) _a = (a);\
__typeof__ (b) _b = (b);\
_a < _b ? _a : _b; })

int *allPosibilities();

void calculateMatches(const int *secret, const int *guess, int *resultOut);

void filterList(int *allPermutations, bool *validMask, int *currentGuess, int userRightPlace, int userWrongPlace);

#endif //LABS_MASTER_MIND_H
