//
// Created by serhi on 12/23/2025.
//

#include <stdio.h>
#include <stdlib.h>

void nextPermutation(int *currentPerm, int n);

void swap(int *a, int *b);

void reverse(int *arr, int start, int end);

bool checkNextPerm(int *currentPerm, int n);

long long factorial(int n);

int main() {
    int n;
    printf("Enter number of columns (N): ");
    scanf("%d", &n);

    int *currentPerm = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        currentPerm[i] = i + 1;
    }

    long long totalPermutations = factorial(n);
    int solutionCount = 0;
    for (long long k = 0; k < totalPermutations; k++) {
        if (checkNextPerm(currentPerm, n)) {
            solutionCount++;
            printf("Solution %d: ", solutionCount);
            for (int j = 0; j < n; j++) {
                printf("%d ", currentPerm[j]);
            }
            printf("\n");
        }
        nextPermutation(currentPerm, n);
    }

    if (solutionCount == 0) {
        printf("No solutions found.\n");
    } else {
        printf("\nTotal solutions found: %d\n", solutionCount);
    }

    free(currentPerm);
    return 0;
}

bool checkNextPerm(int *currentPerm, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int colDiff = j - i;
            int rowDiff = abs(currentPerm[i] - currentPerm[j]);

            if (rowDiff == colDiff) {
                return false;
            }
        }
    }
    return true;
}

long long factorial(int n) {
    long long f = 1;
    for (int i = 1; i <= n; i++) {
        f *= i;
    }
    return f;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(int *arr, int start, int end) {
    while (start < end) {
        swap(&arr[start], &arr[end]);
        start++;
        end--;
    }
}

void nextPermutation(int *currentPerm, int n) {
    int i = n - 2;
    while (i >= 0 && currentPerm[i] >= currentPerm[i + 1]) {
        i--;
    }

    if (i >= 0) {
        int j = n - 1;
        while (j >= 0 && currentPerm[j] <= currentPerm[i]) {
            j--;
        }
        swap(&currentPerm[i], &currentPerm[j]);
    }

    reverse(currentPerm, i + 1, n - 1);
}
