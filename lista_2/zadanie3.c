#include <stdio.h>
#include <math.h>

void dividers(int n)
{
	int d = sqrt(n);
	int i = 3;
	int cur = i;
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
		printf("%d^%d*", cur, mult);
	}
}

int main()
{
	int n;
	printf("Enter number: ");
	scanf("%d", &n);
	dividers(n);

	return 0;
}