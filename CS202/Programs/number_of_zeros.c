#include<stdio.h>
int zero(int n);
int main()
{
    int n, c=0;
    printf("Enter number: ");
    scanf("%d", &n);
    c = zero(n);
    printf("%d", c);
    return 0;
}
int zero(int n) 
{
    if(n == 0) 
    {
        return 0;
    }
    else
    {
        if(n%10 == 0) 
        {
            return 1 + zero(n/10);
        }
        else {
            zero(n/10);
        }
    }
}