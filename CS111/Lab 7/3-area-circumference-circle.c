#include<stdio.h>
#include<math.h>
#define PI acos(-1) 
void calculation(double r, double *area, double *circumferemce);
int main()
{
    double r;
    double *p, area, circumference;
    p = &r;
    printf("Enter radius of the circle: ");
    scanf("%lf", &r);
    calculation(r, &area, &circumference);
    printf("Area = %lf\n", area);
    printf("Circumference = %lf\n", circumference);
    return 0;
}
//calculating area and circumference
void calculation(double r, double *area, double *circumferemce)
{
    *area = PI * r * r;
    *circumferemce = 2 * PI * r;
}