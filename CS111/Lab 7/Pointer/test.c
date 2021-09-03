#include<stdio.h>
void increment(int *a)
{
    *a = *a+2;
}
int main()
{
    int a = 10;
    increment(&a);
    printf("%d",a);
    return 0;
}