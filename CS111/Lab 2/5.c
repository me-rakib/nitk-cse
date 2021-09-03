#include<stdio.h>
int main()
{
    float BP, DA, HRA, GP;
    printf("Enter Basic Pay: ");
    scanf("%f",&BP);

    //Calculation
    DA = BP*40/100;
    HRA = BP*20/100;
    GP = BP+DA+HRA;

    printf("\nGross Pay: %.2f\n",GP);
    return 0;
}
