#include <stdio.h>
#include <math.h>
double sum_of_series(int n);
int main()
{
    int n;
    double res;
    printf("Evaluate n + n^2 + n^3 + .... + n^n\n");
    printf("Enter the value of n: ");
    scanf("%d", &n);
    res = sum_of_series(n);
    printf("\nSum of the series = %.2lf\n", res);
    return 0;
}

double sum_of_series(int n)   //function 
{
    double sum, p;
    p = pow(n,n);
    sum = (n * (p - 1)) / (float) (n-1);
    return sum;
}