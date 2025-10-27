#include <stdio.h>

int euklides(int a, int b)
{
	if(a == 0)
	{
		return b;
	}
	if(b == 0)
	{
		return a;
	}

	int temp;

	while (b != 0)
	{
		temp = b;
		b = a % b;
		a = temp;
	}

	return a;
}

int main()
{
	int a;
	int b;
	printf("Enter a: ");
	scanf("%d", &a);
	printf("Enter b: ");
	scanf("%d", &b);
	printf("%d", euklides(a, b));

	return 0;
}