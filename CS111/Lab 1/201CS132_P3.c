// program to calculate the third angle of a triangle

#include<stdio.h>
int main()
{
    int A, B, C;
    printf("Enter the angles\n");
    printf("A = ");
    scanf("%d",&A);
    printf("B = ");
    scanf("%d",&B);
    if((A+B<180))
    {
        int C;
        if(A>B)
        {
            C = 180-A-B;
        }
        else
        {
            C = 180- B-A;
        }
        printf("\nThird angle C = %d\n",C);
    }
    else
    {
        printf("\nInvalid Inputs are taken\n");
    }
    return 0;
}
