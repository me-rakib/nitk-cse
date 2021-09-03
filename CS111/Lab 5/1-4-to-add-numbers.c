#include<stdio.h>
int add_numbers(int *nums, int len);
int main()
{
    int n, res, i;
    printf("How many number you want to add: ");
    scanf("%d", &n);
    int numbers[n];
    printf("Enter numbers: ");
    for(i=0; i<n; i++) 
    {
        scanf("%d",(numbers+i));  //taking input
    }
    res = add_numbers(numbers, n);
    printf("\nTotal is = %d\n",res);
    return 0;
}

int add_numbers(int *nums, int len)  //function  
{
    int i, sum = 0;
    for(i=0; i<len; i++) 
    {
        sum += *(nums+i);
    }
    return sum;
}