#include<stdio.h>
int main() 
{
    int num;
    printf("Enter a number: ");
    scanf("%d",&num);
    printf("Factors of %d = ",num);
    int i;
    for(i=1; i<=num; i++)
    {
        if(i==num) 
        {
            printf("%d",i); //remove comma after last factor
        }
        else if (num%i==0) 
        {
            printf("%d, ",i);
        }
    }
    return 0;    
}