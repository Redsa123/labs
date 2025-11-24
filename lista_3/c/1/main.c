//
// Created by redsa on 23.11.25.
//
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "primenumbers.h"

int main(int argc, char* argv[]){
    unsigned long n, count;
    bool *s;

    if (argc!=2) {
        printf("Wrong number of arguments\n");
        return -1;
    }


    sscanf(argv[1], "%lu", &n);
    s = malloc((n+1)*sizeof(bool));

    compute_sieve(s, n);
    count = count_primes(s, n);

    free(s);

    printf("%lu\n", count);

    return 0;
}