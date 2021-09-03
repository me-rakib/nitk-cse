#include<stdio.h>
#define PI 3.1416
int main()
{
    int radius;
    float area, perimeter;
    printf("Enter the radius of a circle: ");
    scanf("%d", &radius);

    //calculating area and perimeter
    area = PI*radius*radius;
    perimeter = (2*PI*radius);

    printf("\nArea = %.2f\n", area);
    printf("Perimeter = %.2f\n", perimeter);

    return 0;
}
