#include<stdio.h>
int main()
{
    float total_amount, rate, time, s_i, c_i;
    printf("Enter total amount: ");
    scanf("%f",&total_amount);
    printf("Enter rate(%%): ");
    scanf("%f",&rate);
    rate = rate/100;
    printf("Enter time(year): ");
    scanf("%f",&time);

    //calculating simple and compound interests
    simple_interest = amount*(rate/100)*time;
    compound_interest = (amount*(pow((1+(rate/100)),time)))-amount;

    printf("\nSimple Interest = %.2f\n",s_i);
    printf("Compound Interest = %.2f\n",c_i);
    return 0;
}
