//
// Created by serhi on 12/22/2025.
//

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void mastermind();

int main() {
    mastermind();

    return 0;
}

void mastermind() {
    int answer[4] = {1, 1, 1, 1};
    int try = 1;
    while (true) {
        printf("%d:\t", try);
        for (int i = 0; i < sizeof(answer) / sizeof(answer[0]); i++) {
            printf("%d ", answer[i]);
        }
        printf("?\n");

        int rightPlace;
        int wrongPlace;

        printf("On the right place: ");
        scanf("%d", &rightPlace);
        printf("On the wrong place: ");
        scanf("%d", &wrongPlace);

        if (rightPlace == 4) {
            return;
        }


        return;
    }
}
