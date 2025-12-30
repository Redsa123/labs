#include <stdio.h>
#include <math.h>

double EPSILON = 0.1;

typedef double (*functype)(double);

void write(functype f, double x)
{
    printf("%f\n", f(x));
}

double square1(double x)
{
    return (x - 1.0) * (x + 2.0);
}

double testFunc(double x)
{
    return cos(x / 2.0);
}

double findzero(functype f, double a, double b, double eps)
{
    double mid = (a + b) / 2;

    if (f(mid) == 0.0)
    {
        return mid;
    }

    while ((b - a) / 2 > eps)
    {
        if (f(a) * f(mid) < 0)
        {
            b = mid;
        }
        else
        {
            a = mid;
        }
        mid = (a + b) / 2;
    }

    return mid;
}

int main()
{
    double a, b;
    int precision;
    printf("Enter a: ");
    scanf("%lf", &a);
    printf("Enter b: ");
    scanf("%lf", &b);
    printf("Choose precision: ");
    scanf("%d", &precision);

    for (int i = 1; i <= precision; i++)
    {
        double result = findzero(testFunc, a, b, pow(EPSILON, i));
        printf("result: %.20f\n", result);
    }

    return 0;
}