#include <stdio.h>
int fibonacci(int n, int n1, int n2);
int main()
{
    int n, n1=0, n2=1;
    printf("Enter the number: ");
    scanf("%d", &n);
    printf("Fibonacci series upto %d: ", n);
    printf("%d %d ", n1, n2);
    fibonacci(n, n1, n2);
    printf("\n");
    return 0;
}

int fibonacci(int n, int n1, int n2)  // function
{
    int temp = n1 + n2;
    if(temp>=n) 
    {
        return 0;
    }
    else 
    {
        printf("%d ",temp);
        n1 = n2;
        n2 = temp;
        fibonacci(n, n1, n2);
    }
}