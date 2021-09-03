#include<stdio.h>
int main() 
{
    int n, i;
    printf("Total number in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the element of array: ");
    for(i=0; i<n; i++)
    {
        scanf("%d", (arr+i));
    }
    printf("Reverse array: ");
    for(i=n-1; i>=0; i--) 
    {
        printf("%d ", *(arr+i));
    }
    return 0;
}