#include <stdio.h>
#include <math.h>

void dividers(long long n)
{
	long long d = sqrt(n);
	long long i = 3;
	long long cur = i;
	int mult2 = 0;

	if (n % 2 == 0)
	{
		while (n % 2 == 0)
		{
			mult2++;
			n /= 2;
		}
		printf("2^%d*", mult2);
	}

	while (i <= n)
	{
		int mult = 0;
		while (n % i == 0)
		{
			cur = i;
			mult++;
			n /= i;
		}
		i += 2;
		if (mult == 0)
		{
			continue;
		}
		printf("%lld^%d*", cur, mult);
	}
}

int main()
{
	long long n;
	printf("Enter number: ");
	scanf("%lld", &n);
	dividers(n);

	return 0;
}