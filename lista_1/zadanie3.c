#include <stdio.h>
#include <stdbool.h>

int is_palindrome(int x, int n)
{
	int m = 0;
	int t = x;
	while (t > 0)
	{
		m = n * m + (t%n);
		t = t / n;
	}
	return (m==x);
}

int main()
{
	printf("%d", is_palindrome(3, 2));

	return 0;
}