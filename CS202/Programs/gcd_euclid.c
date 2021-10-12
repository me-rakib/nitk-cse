#include<stdio.h>
int gcd(int n1, int n2);
int main()
{
    int n1, n2, res;
    printf("Enter two number: ");
    scanf("%d %d", &n1, &n2);
    res = gcd(n1, n2);
    printf("GCD = %d", res);
    return 0;
}

int gcd(int n1, int n2) 
{
    int a, b;
    if(n1 == 0 || n2 == 0) 
    {
        return n1 == 0? n2 : n1;
    }
    else 
    {
        a = n1 < n2 ? n1 : n2;
        b = n1 > n2 ? n1 : n2;
        gcd(a, b%a);
    }
}