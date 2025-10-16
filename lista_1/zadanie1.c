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

	int modulo;

	while (b != 0)
	{
		modulo = b;
		b = a % b;
		a = modulo;
	}

	return a;
}

int main()
{
	printf("%d", euklides(24, 12));

	return 0;
}