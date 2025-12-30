//
// Created by redsa on 23.11.25.
//
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "primenumbers.h"

int main(int argc, char* argv[]){
    long long n, count;
    bool *s;

    if (argc!=2) {
        printf("Wrong number of arguments\n");
        return 1;
    }

    sscanf(argv[1], "%lld", &n);

    if (n < 0) {
        printf("Arguments have to be greater than 0");
        return 1;
    }

    if (n < 2) {
        printf("No prime numbers less than 2\n");
        return 1;
    }

    s = malloc((n+1)*sizeof(bool));

    compute_sieve(s, n);
    count = count_primes(s, n);

    free(s);

    printf("%lld\n", count);

    return 0;
}