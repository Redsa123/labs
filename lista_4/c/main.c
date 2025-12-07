#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "primes_lib.h"

int main(int argc, char* argv[]) {
	if (argc != 3) {
		printf("Wrong number of arguments.\nUsage: ./program <function> <number>");
		return 1;
	}

	char* func_name = argv[1];
	unsigned number = atoi(argv[2]);

	if (!strcmp(func_name, "pn")) {
		printf("Number of prime numbers less or equal to %u: %u", number, prime_numbers(number));
	}

	if (!strcmp(func_name, "pr")) {
		printf("%u-th prime number: %u", number, prime(number));
	}

	if (!strcmp(func_name, "ip")) {
		char* result = is_prime(number) ? "true" : "false";
		printf("Is %u a prime number:\n%s", number, result);
	}
	
	return 0;
}