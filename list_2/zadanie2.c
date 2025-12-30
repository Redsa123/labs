#include <stdio.h>
#include <math.h>

bool isPrime(int n)
{
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

int main()
{
	int n;
	printf("Enter number: ");
	scanf("%d", &n);
	printf("%s", isPrime(n) ? "true" : "false");
}