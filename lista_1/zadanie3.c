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
	int num;
	int sys;
	printf("Enter number: ");
	scanf("%d", &num);
	printf("Enter system: ");
	scanf("%d", &sys);
	printf("%d", is_palindrome(num, sys));

	return 0;
}