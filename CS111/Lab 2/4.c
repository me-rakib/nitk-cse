#include<stdio.h>
int main()
{
    int roll;
    float marks1, marks2, marks3, sum, avg;
    printf("Enter roll: ");
    scanf("%d",&roll);
    printf("Enter marks1, marks2 & marks3: ");
    scanf("%f %f %f",&marks1, &marks2, &marks3);
    // calculation
    sum = marks1+marks2+marks3;
    avg = sum/3;
    printf("\nRoll %d:\n",roll);
    printf("Total marks = %.2f\n", sum);
    printf("Average marks = %.2f\n",avg);
    return 0;
}
