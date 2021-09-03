#include<stdio.h>
#include<math.h>
int main()
{
    int a,b,c;
    printf("Enter the value for a, b & c: ");
    scanf("%d %d %d",&a, &b, &c);
    int sq_a, sq_b, sq_c;
    sq_a = pow(a,2);
    sq_b = pow(b,2);
    sq_c = pow(c,2);
    if(a >= b+c)
        printf("No triangle");
    else if(sq_a == (sq_b+sq_c))
        printf("Right Angled triangle");
    else if(sq_a > (sq_b+sq_c))
        printf("Obtuse triangle");
    else if(sq_a < (sq_b+sq_c))
        printf("Acute triangle");
    else if((a==b) && (a==c))
        printf("Equilateral triangle");
    else if((a==b) || (a==c) || (b==c))
        printf("Isosceles triangle");
    else
        printf("Scalene triangle");
    return 0;
}
