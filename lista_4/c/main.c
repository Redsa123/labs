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
	} else if (!strcmp(func_name, "pr")) {
		printf("%u-th prime number: %u", number, prime(number));
	} else if (!strcmp(func_name, "ip")) {
		char* result = is_prime(number) ? "true" : "false";
		printf("Is %u a prime number:\n%s", number, result);
	} else if (strcmp(func_name, "pn") != 0 && strcmp(func_name, "pr") != 0 && strcmp(func_name, "ip") != 0) {
		printf("\"%s\" is unknown function.\nAvailable functions:\n\"pn\" for number of prime numbers less or equal to provided number;\n\"pr\" for n-th prime number\n\"ip\" for checking if provided number if prime", func_name);
	}
	
	return 0;
}