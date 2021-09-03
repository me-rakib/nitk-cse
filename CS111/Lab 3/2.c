#include <stdio.h>
#include <math.h>
int main()
{
    float a, b, c;
    printf("Enter the value of a, b & c: ");
    scanf("%f %f %f", &a, &b, &c);
    if (a != 0)     //a^2 + b + c = 0 so a!=0
    {
        float discriminate, root_1, root_2;
        discriminate = pow(b, 2) - 4 * a * c;
        if (discriminate >= 0)
        {
            root_1 = (-b + sqrt(discriminate)) / (2 * a);
            root_2 = (-b - sqrt(discriminate)) / (2 * a);
            printf("\nValue of x1 = %.2f\n", root_1);
            printf("Value of x2 = %.2f\n", root_2);
        }
        else
        {
            float real, imaginary;
            real = (-b) / (2 * a);
            imaginary = (sqrt(-(discriminate))) / (2 * a);
            printf("\nRoot 1 = %.2f + (%.2fi)\n", real, imaginary);
            printf("Root 2 = %.2f - (%.2fi)\n", real, imaginary);
        }
    }
    return 0;
}