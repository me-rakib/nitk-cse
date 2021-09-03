#include<stdio.h>
int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    int remainder, sum=0, reverse=0;
    while (num != 0)
    {
        remainder = num % 10; //separate last digit
        sum += remainder;     //add
        reverse = reverse*10 + remainder;  //reverse 
        num /= 10;
    }
    printf("\nSum of the digits = %d\n",sum);
    printf("Reverse number = %d\n",reverse);
    return 0;
    
}
