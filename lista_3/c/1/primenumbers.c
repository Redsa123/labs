//
// Created by redsa on 23.11.25.
//

#include "primenumbers.h"
#include <math.h>

void compute_sieve (bool s[], unsigned n){
	unsigned root = sqrt(n);

	s[2] = true;

	for (unsigned i = 3; i <= n; i+=2) s[i] = true;

	for (unsigned i = 3; i <= root; i+=2) {
		if (s[i]) {

			/*Because i is odd, i*i is odd, so i*i+i is even, so j+=2*i to iterate only over odd numbers*/
			for (unsigned j = i*i; j <= n; j+=2*i) {
				s[j] = false;
			}
		}
	}
}


unsigned long count_primes (bool s[], unsigned n) {
	unsigned long count;

	if (n>=2) {
		count = 1;
	}

	for (unsigned i = 3; i <= n; i+=2) {
		if (s[i]) count++;
	}

	return count;
}