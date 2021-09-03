#include <stdio.h>
int main()
{
    int n1, n2, temp;
    int *p1 = &n1, *p2 = &n2;
    printf("Enter num1: ");
    scanf("%d", &n1);
    printf("Enter num2: ");
    scanf("%d", &n2);
    printf("Before swipe num1 = %d & num2 = %d\n", n1, n2);
    //swappingP
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
    printf("After swipe num1 = %d & num2 = %d\n", n1, n2);
    return 0;
}