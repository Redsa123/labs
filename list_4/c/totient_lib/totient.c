#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "totient.h"

void dividers(unsigned n, int *dividers_list, int *index);

unsigned totient(unsigned n) {
	int *dividers_list = malloc(sizeof(int) * log2(n));
	int index = 0;
	dividers(n, dividers_list, &index);

	unsigned res = n;
	for (int i = 0; i < index; i++) {
		res = res - res/dividers_list[i];
	}

	free(dividers_list);
    return res;
}

void dividers(unsigned n, int *dividers_list, int *index) {
	if (n % 2 == 0) {
		while (n % 2 == 0) {
			n /= 2;
			if (!(n % 2 == 0)) {
				dividers_list[*index] = 2;
				*index = *index + 1;
			}
		}
	}

	long long const sqrroot = sqrt(n);
	long long i = 3;
	while (i <= sqrroot)
	{
		if (n%i==0)
		{
			while (n%i==0)
			{
				n /=i;
				if (!(n % i == 0)) {
					dividers_list[*index] = i;
					*index = *index + 1;
				}
			}
		}
		i+=2;
	}

	if (n > 1) {
		dividers_list[*index] = n;
		*index = *index + 1;
	}
}