#include <stdio.h>
#include <math.h>

void solve(float a, float b, float c)
{
	float delta = b*b - 4*a*c;

	if (delta < 0)
	{
		printf("Rozwiazania rownania nie naleza do zbioru liczb rzeczywistych\n");
	}
	else if (delta == 0)
	{
		printf("%f\n", ((-1 * b) / (2*a)));
	}
	else
	{
		printf("%f, %f", ((-1*b-sqrt(delta))/(2*a)), ((-1*b+sqrt(delta))/(2*a)));
	}

}

int main()
{
	float a;
	float b;
	float c;
	printf("Enter value a: ");
	scanf("%f", &a);
	printf("Enter value b: ");
	scanf("%f", &b);
	printf("Enter value c: ");
	scanf("%f", &c);

	solve(a, b, c);

	return 0;
}