//
// Created by redsa on 26.11.25.
//

/*
Takes N as argument and returns Nth prime number;
*/

#include <stdio.h>
#include <stdlib.h>

long long nth_prime(int n);

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Wrong number of arguments.\n");
    }

    int n = atoi(argv[1]);
    printf("%lld\n",nth_prime(n));
    return 0;
}

long long nth_prime(int n) {
    if (n <= 0) {
        printf("Wrong arguments, n has to be greater than 0\n");
        return -1;
    }
    if (n == 1) {
        return 2;
    }

    long long* primes = malloc(n * sizeof(long long));

    int count = 1;
    primes[0] = 2;

    int i = 3;
    int flag = 1;

    while (1) {
        flag = 1;

        for (int j = 0; j < count; j++) {
            if (i%primes[j] == 0) {
                flag = 0;
            }
        }

        if (flag) {
            primes[count] = i;
            count++;
        }

        if (count == n) {
            free(primes);
            return i;
        }
        i += 2;
    }
}
