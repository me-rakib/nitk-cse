#include<stdio.h>
#define MAX_SIZE 100
int main()
{
    int n, i, j, arr[MAX_SIZE][MAX_SIZE], symmetric[MAX_SIZE][MAX_SIZE];
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++) 
        {
            scanf("%d", &arr[i][j]);
            symmetric[j][i] = arr[i][j];
        }
    }
    for(i=0; i<n; i++) 
    {
        for(j=0; j<n; j++) 
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    for(i=0; i<n; i++) 
    {
        for(j=0; j<n; j++) 
        {
            printf("%d ", symmetric[i][j]);
        }
        printf("\n");
    }
}