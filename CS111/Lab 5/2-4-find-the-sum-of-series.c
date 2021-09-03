// find the sum of the series 1 + 1/3! + 1/5! + ... + 1/N!

#include <stdio.h>
double sum(int n, int n1, double s);
int main()
{
    int n;
    double res;
    printf("Enter N: ");
    scanf("%d", &n);
    res = sum(n, 1, 0);
    printf("%lf\n", res);
    return 0;
}

double sum(int n, int n1, double s)
{
    int fact = 1, i;
    for (i = 1; i <= n1; i++)
    {
        fact *= i;
    }
    if (n1 > n)
    {
        return s;
    }
    else
    {
        s = s + (1.0 / fact);
        sum(n, n1 + 2, s);
    }
}
