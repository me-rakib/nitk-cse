#include<stdio.h>
int fact(int n);
int main()
{
    int n, res;
    printf("Enter Number: ");
    scanf("%d", &n);
    res = fact(n);
    printf("\nFactorial of %d is %d\n",n,res);
    return 0;
}
int fact(int n)   // recursion function
{
    if(n==1) 
    {
        return 1;
    }
    else 
    {
        return n * fact(n-1);
    }
}