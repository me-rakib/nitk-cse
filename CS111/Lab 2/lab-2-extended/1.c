#include<stdio.h>
int main()
{
    float dis_in_km;
    printf("Enter the distance(km): ");
    scanf("%f", &dis_in_km);
    float dis_in_mtr, dis_in_ft, dis_in_inch, dis_in_cm;

    // calculate
    dis_in_mtr = dis_in_km * 1000;
    dis_in_ft = dis_in_km * 3280.84;
    dis_in_inch = dis_in_km * 39370.1;
    dis_in_cm = dis_in_km * 100000;

    // printing
    printf("\nDistance in meters: %.2f\n", dis_in_mtr);
    printf("Distance in feet: %.2f\n", dis_in_ft);
    printf("Distance in inches: %.2f\n", dis_in_inch);
    printf("Distance in centimeters: %.2f\n", dis_in_cm);
    return 0;
}
