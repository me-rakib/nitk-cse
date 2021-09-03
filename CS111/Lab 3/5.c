#include<stdio.h>
int main()
{
    float marks;
    printf("Enter the marks: ");
    scanf("%f",&marks);
    if((marks>=90) && (marks<=100))
        printf("A+");
    else if((marks>=80) && (marks<=89))
        printf("A");
    else if((marks>=70) && (marks<=79))
        printf("B");
    else if((marks>=60) && (marks<=69)) 
        printf("C");
    else if((marks>=50) && (marks<59)) 
        printf("D");
    else if((marks>=40) && (marks<=49))
        printf("E");
    else if((marks>=0) && (marks<40))
        printf("Fail");
    else
        printf("Ivalid Input");
    return 0;
}