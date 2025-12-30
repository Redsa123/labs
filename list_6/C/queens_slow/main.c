//
// Created by serhi on 12/23/2025.
//

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h> // Required for abs()

void nextPermutation(int *nums, int n);

void swap(int *a, int *b);

void reverse(int *nums, int start, int end);

bool checkNextPerm(int *nums, int n);

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

bool checkNextPerm(int *nums, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int colDiff = j - i;
            int rowDiff = abs(nums[i] - nums[j]);

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

void reverse(int *nums, int start, int end) {
    while (start < end) {
        swap(&nums[start], &nums[end]);
        start++;
        end--;
    }
}

void nextPermutation(int *nums, int n) {
    int i = n - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }

    if (i >= 0) {
        int j = n - 1;
        while (j >= 0 && nums[j] <= nums[i]) {
            j--;
        }
        swap(&nums[i], &nums[j]);
    }

    reverse(nums, i + 1, n - 1);
}
