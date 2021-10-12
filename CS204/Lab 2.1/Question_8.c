#include<stdio.h>
int ncr(int n);
int main()
{
    //redirecting input and output
    freopen("input_8.txt", "r", stdin);
    freopen("output_8.txt", "w", stdout);

    int n, r;
    scanf("%d %d",&n,&r);
    printf("%d ", ncr(n)/(ncr(r)*ncr(n-r)));
    return 0;
}

int ncr(int n) 
{
    if(n==1) 
    {
        return 1;
    }
    else
    {
        return n * ncr(n-1);
    }
}