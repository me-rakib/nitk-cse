#include<stdio.h>
#define MAX_SIZE 100
int main()
{
    int r,c, i, j, arr[MAX_SIZE][MAX_SIZE], transpose[MAX_SIZE][MAX_SIZE];
    printf("Enter row and col: ");
    scanf("%d %d", &r, &c);
    for(i=0; i<r; i++) 
    {
        for(j=0; j<c; j++) 
        {
            scanf("%d", &arr[i][j]);
        }
    }
    for(i=0; i<c; i++) 
    {
        for(j=0; j<r; j++) 
        {
            transpose[i][j] = arr[j][i];
        }
    }
    for(i=0; i<c; i++) 
    {
        for(j=0; j<r; j++) 
        {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }
}
