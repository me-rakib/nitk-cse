// selection sort 
#include<stdio.h>
#define MAX_SIZE 100
int main() 
{
    int arr[MAX_SIZE], n, i, j, temp;
    printf("Enter total element: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for(i=0; i<n; i++) 
    {
        scanf("%d", (arr+i));
    }
    for(i=0; i<n; i++) 
    {
        for(j=i+1; j<n; j++) 
        {
            if(arr[i]>arr[j]) 
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp; 
            }
        }
    }
    printf("Sorted array: ");
    for(i=0; i<n; i++) 
    {
        printf("%d ", *(arr+i));
    }
    return 0;
}


/*
//Bubble sort
#include<stdio.h>
#define MAX_SIZE 100
int main() 
{
    int arr[MAX_SIZE], n, i, j, temp;
    printf("Total element size: ");
    scanf("%d", &n);
    printf("Enter array element: ");
    for(i=0; i<n; i++) 
    {
        scanf("%d", (arr+i));
    }
    for(i=0; i<n; i++) 
    {
        for(j=0; j<(n-i-1); j++) 
        {
            if(arr[j]>arr[j+1]) 
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp; 
            }
        }
    }
    for(i=0; i<n; i++) 
    {
        printf("%d ",*(arr+i));
    }
    return 0;
}
*/