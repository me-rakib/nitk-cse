#include<stdio.h>
int main()
{
    float n1, n2;
    printf("Enter the value for Number1 & Number2: ");
    scanf("%f %f",&n1,&n2);
    printf("\nBefore swipe number1 = %f & number2 = %f\n",n1, n2);

    //swipe
    float temp = n1;
    n1 = n2;
    n2 = temp;

    printf("After swipe number1 = %f & number2 = %f\n",n1, n2);
    return 0;
}
