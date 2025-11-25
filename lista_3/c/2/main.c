#include <stdio.h>
#include <stdlib.h>

long long calcNewton(unsigned n, unsigned k);

int main(int argc, char* argv[]) {
	long long n = atoi(argv[1]);
	long long k = atoi(argv[2]);

	if (argc != 3) {
		printf("Wrong number of arguments");
		return -1;
	}
	if (k < 0 || n < 0) {
		printf("Arguments have to be greater than 0\n");
		return -1;
	}
	if (k > n) {
		printf("Wrong arguments, k has to be greater than n.\nUsage: ./main <n> <k>\n");
		return -1;
	}

	// Optimisation for (n,k) = (n, n-k) (formula)
	if (k > n / 2) {
		k = n - k;
	}
	if (k == n) {
		return -1;
	}



	printf("Result: %llu\n", calcNewton(n, k));
}

long long calcNewton(unsigned n, unsigned k) {
	long long* tab = calloc((k+1), sizeof(long long));

	tab[0] = 1;

	// Pascal triangle
	for (unsigned i = 1; i <= n; i++) {
		int j_max = (i < k) ? i : k;

		for (unsigned j = j_max; j > 0; j--) {
			tab[j] = tab[j]+tab[j-1];
		}
	}

	long long result = tab[k];
	free(tab);

	return result;
}