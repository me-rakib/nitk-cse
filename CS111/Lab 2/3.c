#include<stdio.h>
int main()
{
    float F, C;
    printf("Enter temperature in Fahrenheit: ");
    scanf("%f", &F);

    //convert temperature into degree centigrade
    C = (F-32)*5/9;

    printf("\nTemperature in degree centigrade: %.2f\n", C);
    return 0;
}
