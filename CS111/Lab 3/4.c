#include<stdio.h>
int main()
{
    float num1, num2;
    printf("Enter two number: ");
    scanf("%f %f", &num1, &num2);
    printf("\nMenu\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Close\n");
    int choice;
    printf("Enter your choice: ");
    scanf("%d",&choice);
    float result;
    switch(choice)
    {
    case 1:
        result = num1 + num2;
        break;
    case 2:
        result = num1 - num2;
        break;
    case 3:
        result = num1 * num2;
        break;
    case 4:
        result = num1 / num2;
        break;
    case 5:
        printf("\nClosed\n");
        return 0;
    default:
        printf("\nInvalid Input\n");
        return 0;
    }
    printf("\nResult = %.2f\n",result);
    return 0;
}
