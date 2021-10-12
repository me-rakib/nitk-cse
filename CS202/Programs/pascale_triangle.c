#include<stdio.h>
int main()
{
    int n, i, j, c;
    printf("Enter N: ");
    scanf("%d", &n);
    for(i=1; i<=n; i++) 
    {
        for(j=1; j<=n-i; j++) 
        {
            printf("  ");
        }
        c = 1;
        for(j=1; j<=i; j++) 
        {
            printf("%d   ",c);
            c = c * (i-j)/j;
        }
        printf("\n");
    }
}