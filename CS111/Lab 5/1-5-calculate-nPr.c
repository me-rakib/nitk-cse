#include <stdio.h>
int fact(int n);
int permutation(int n, int r);
int main()
{
    int n, r, res;
    printf("Enter the value for n & p: ");
    scanf("%d %d", &n, &r);
    if (n >= r)
    {
        res = permutation(n, r);
        printf("P(%d,%d) = %d", n, r, res);
    }
    else
    {
        printf("Math Error");
    }
    return 0;
}

int fact(int n)
{
    int i, fact = 1;
    for(i=1; i<=n; i++) 
    {
        fact *= i;
    }
    return fact;
}

int permutation(int n, int r)
{
    return (fact(n) / fact(n-r));   
}
