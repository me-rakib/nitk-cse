// program to find out the ans of (a-b)^2 with and without using the pow function
#include<stdio.h>
#include<math.h>
int main()
{
    int a, b, res;
    printf("Enter value of A: ");
    scanf("%d",&a);
    printf("Enter value of B: ");
    scanf("%d",&b);

    //with pow
    int c = (a-b);
    res = pow(c,2);
    printf("\nUsing pow function result = %d\n",res);

    //without pow function
    res = (a*a) - (2*a*b) + (b*b);
    printf("\nWithout using pow function result = %d\n",res);
    return 0;
}
