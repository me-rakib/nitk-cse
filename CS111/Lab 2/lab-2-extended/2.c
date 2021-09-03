#include<stdio.h>
#define PI 3.1416
int main()
{
    float length, breadth, radious;
    printf("Enter Length, Breadth & Radious: ");
    scanf("%f %f %f",&length, &breadth, &radious);
    float rect_area, rect_perimeter, circ_area, circ_circum;
    // calculation
    rect_area = length * breadth;
    rect_perimeter = 2*(length+breadth);
    circ_area = PI*radious*radious;
    circ_circum = 2*PI*radious;
    //printing
    printf("\nArea (rectangle): %.2f\n",rect_area);
    printf("Perimeter (rectangle): %.2f\n",rect_perimeter);
    printf("Area (circle): %.2f\n",circ_area);
    printf("Circumference (circle): %.2f\n",circ_circum);
    return 0;
}
