#include<stdio.h>
#include<math.h>
int main()
{
    float num, res_sqrt, res_sqr;
    printf("Enter number(0<num<101): ");
    scanf("%f",&num);
    if((num>0) && (num<=100))
    {
        res_sqrt = sqrt(num);
        res_sqr = pow(num, 2);
        printf("\nSquare root = %.2f\nSqware = %.2f\n", res_sqrt, res_sqr);
    }
    else
        printf("Invalid Input");
    return 0;
}
