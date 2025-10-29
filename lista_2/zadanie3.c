#include <stdio.h>
#include <math.h>

void dividers(long long n) {
	if (n % 2 == 0) {
		int mult2 = 0;
		while (n % 2 == 0) {
			mult2++;
			n /= 2;
		}
		printf("2^%d", mult2);
		if (n > 1) printf("*");
	}

	long long root = sqrt(n);
	long long i = 3;
	while (i <= root)
	{
		if (n%i==0)
		{
			int mult = 0;
			while (n%i==0)
			{
				mult++;
				n /=i;
			}
			printf("%lld^%d", i, mult);
			if(n>1) printf("*");
		}
		i+=2;
	}

	if (n > 1) {
		printf("%lld^1", n);
	}
}

int main() {
	long long n;
	printf("Enter number: ");
	scanf("%lld", &n);
	dividers(n);
	printf("\n");
	return 0;
}
