// insert an element in a specified position
#include<stdio.h>
#define MAX_SIZE 1000
int main() 
{
    int arr[MAX_SIZE], i, n, pos, val;
    printf("Total element: ");
    scanf("%d", &n);
    printf("Enter array element: ");
    for(i=0; i<n; i++) 
    {
        scanf("%d", (arr+i));
    } 
    printf("Enter array position and number: ");
    scanf("%d %d",&pos,&val);
    if(pos>=0 && pos<n) 
    {
        for(i=n; i>=pos; i--) 
        {
            arr[i] = *(arr+(i-1));
        }
        arr[pos-1] = val;
        for(i=0; i<=n; i++) 
        {
            printf("%d ",*(arr+i));
        }
    }
    return 0;
}


/*
// insert an element in a specified position
#include<stdio.h>
#define MAX_SIZE 1000
int main() 
{
    int arr[MAX_SIZE], arr1[MAX_SIZE], i, n, pos, val;
    printf("Total element: ");
    scanf("%d", &n);
    printf("Enter array element: ");
    for(i=0; i<n; i++) 
    {
        scanf("%d", (arr+i));
    } 
    printf("Enter array position and number: ");
    scanf("%d %d",&pos,&val);
    for(i=0; i<n+1; i++) 
    {
        if(i<pos) 
        {
            arr1[i] = *(arr+i);
        }
        else if(i==pos) 
        {
            arr1[i] = val;
        }
        else if(i>pos) 
        {
            arr1[i] = *(arr+(i-1));
        }
    }
    printf("Updated array: ");
    for(i=0; i<n+1; i++) 
    {
        printf("%d ",*(arr1+i));
    }
    return 0;
}

*/

/*
// update value of a specified position
#include<stdio.h>
#define MAX_SIZE 1000
int main() 
{
    int arr[MAX_SIZE], i, n, pos, val;
    printf("Total element: ");
    scanf("%d", &n);
    printf("Enter array element: ");
    for(i=0; i<n; i++) 
    {
        scanf("%d", (arr+i));
    } 
    printf("Enter array position and number: ");
    scanf("%d %d",&pos,&val);
    arr[pos] = val;
    printf("Updated array: ");
    for(i=0; i<n; i++) 
    {
        printf("%d ",*(arr+i));
    } 
    return 0;
}

*/