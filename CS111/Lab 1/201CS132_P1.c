// program to swipe two number without using third variable
#include<stdio.h>
void swipe(int n1, int n2);
int main()
{
    int a, b;
    printf("Enter value of a= ");
    scanf("%d",&a);
    printf("Enter value of b= ");
    scanf("%d",&b);
    swipe(a,b);
    return 0;
}
void swipe(int n1, int n2)
{
    n1 = n1+n2;
    n2 = n1-n2;
    n1 = n1-n2;
    printf("\na=%d, b=%d\n",n1,n2);
}
