#include<stdio.h>
int main() 
{
    int n, i, j, sum=0, num1, num2;
    printf("Enter total number: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array element: ");
    for(i=0; i<n; i++) 
    {
        scanf("%d",(arr+i));
    }
    for(i=0; i<n-1; i++) 
    {
        for(j=i+1; j<n; j++) 
        {
            if(sum < (*(arr+i)+*(arr+j)))  //largest sum
            {
                sum = (*(arr+i)+*(arr+j));
                num1 = *(arr+i);
                num2 = *(arr+j);
            }
        }
    }
    printf("Largest sum = %d from num: %d & %d", sum, num1, num2);
    return 0;
}