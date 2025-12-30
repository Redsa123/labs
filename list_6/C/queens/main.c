#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int n;
int* position;
bool* raw;
bool* diagonal1;
bool* diagonal2;
long long solutions;

void queens();
void set(int i);
void printResult();

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Wrong number of arguments\n");
        return 1;
    }
    if (atoi(argv[1]) <= 0) {
        printf("n has to be greater than 0\n");
        return 1;
    }

    n = atoi(argv[1]);

    queens();
    printf("Total number of solutions: %lld\n", solutions);

    return 0;
}

void queens() {
    position = calloc(n, sizeof(int));
    raw = calloc(n, sizeof(bool));
    diagonal1 = calloc(2*n, sizeof(bool));
    diagonal2 = calloc(2*n, sizeof(bool));

    set(0);

    free(position);
    free(raw);
    free(diagonal1);
    free(diagonal2);
}

void set(int i) {
    if (i == n) {
        printResult();
        return;
    }

    for (int j = 0; j < n; j++) {
        int diagonal1_idx = i + j;
        int diagonal2_idx = i - j + (n-1);

        if (!(raw[j] || diagonal1[diagonal1_idx] || diagonal2[diagonal2_idx])) {
            position[i] = j;
            raw[j] = true;
            diagonal1[diagonal1_idx] = true;
            diagonal2[diagonal2_idx] = true;

            set(i + 1);

            position[i] = 0;
            raw[j] = false;
            diagonal1[diagonal1_idx] = false;
            diagonal2[diagonal2_idx] = false;
        }
    }
}

void printResult() {
    solutions++;

    for (int i = 0; i < n; i++) {
        printf("%d ", position[i] + 1);
    }
    printf("\n");
}