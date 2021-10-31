#include<stdio.h>
void fibo(int n, int n1, int n2);

int main()
{
    int n, n1=0, n2=1;
    printf("Enter total number you want: ");
    scanf("%d", &n);
    printf("First %d fibonacci numbers are: %d %d ",n, n1, n2);
    fibo(n, n1, n2);
    return 0;
}

void fibo(int n, int n1, int n2)
{
    int c = 2, temp;
    while(c<n)
    {
        temp = n1+n2;
        n1 = n2;
        n2 = temp;
        printf("%d ",temp);
        c++;
    }
}
