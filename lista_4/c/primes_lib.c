#include "primes_lib.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Function declarations for prime_numbers();
void compute_sieve(bool s[], unsigned n);
unsigned long count_primes(bool s[], unsigned n);

// (pn) returns number of prime number less or equal to n
unsigned prime_numbers(unsigned n) {
    long long count;
    bool* s;

    if (n < 0) {
        printf("Arguments have to be greater than 0");
        return 1;
    }

    if (n < 2) {
        printf("No prime numbers less than 2\n");
        return 1;
    }

    s = malloc((n + 1) * sizeof(bool));

    compute_sieve(s, n);
    count = count_primes(s, n);

    free(s);

    return count;
}

// (pr) returns Nth prime number
unsigned prime(unsigned n) {
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

// (ip) checks if the number is prime
bool is_prime(unsigned n) {
    int root = sqrt(n);

    if(n <= 1)
    {
        return false;
    }

    if (n==2)
    {
        return true;
    }

    if (n%2 == 0)
    {
        return false;
    }

    int i = 3;

    while (i <= root)
    {
        if (n%i == 0)
        {
            return false;
        }
        i += 2;
    }

    return true;
}


void compute_sieve(bool s[], unsigned n) {
	unsigned root = sqrt(n);

	s[2] = true;

	for (unsigned i = 3; i <= n; i += 2) s[i] = true;

	for (unsigned i = 3; i <= root; i += 2) {
		if (s[i]) {

			/*Because i is odd, i*i is odd, so i*i+i is even, so j+=2*i to iterate only odd numbers*/
			for (unsigned j = i * i; j <= n; j += 2 * i) {
				s[j] = false;
			}
		}
	}
}

unsigned long count_primes(bool s[], unsigned n) {
    unsigned long count;

    if (n >= 2) {
        count = 1;
    }

    for (unsigned i = 3; i <= n; i += 2) {
        if (s[i]) count++;
    }

    return count;
}