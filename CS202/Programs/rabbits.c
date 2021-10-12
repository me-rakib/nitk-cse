#include <stdio.h>
int rabbit(int n)
{
    if(n <= 0) 
    {
        return 1;
    }
    else 
    {
        return rabbit(n-1) + rabbit(n-2);
    }
}

int main() 
{
    int n;
    printf("Enter Month: ");
    scanf("%d", &n);
    printf("Total Rabbit: %d", rabbit(n));
    return 0;
}