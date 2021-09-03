// matrices multiplication
#include <stdio.h>
void take_input(int n, int r, int c, int arr[][10]);
int main()
{
    int r1, c1, r2, c2, i, j, k, sum=0;
    int arr1[10][10], arr2[10][10], mul[10][10];
    printf("Enter the value for r1, c1, r2, c2: ");
    scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
    if(r1!=c1)
    {
        printf("Multiplication is not possible");
    }
    else
    {
        take_input(1, r1, c1, arr1);
        take_input(2, r2, c2, arr2);

        //multiplication
        for(i=0; i<r1; i++)
        {
            for(j=0; j<r2; j++)
            {
                for(k=0; k<c2; k++)
                {
                    sum = sum + arr1[i][k] * arr2[k][j];
                }
                mul[i][j] = sum;
                sum = 0;
            }
        }
        for(i=0; i<r1; i++)
        {
            for(j=0; j<c2; j++)
            {
                printf("%d ", *(*(mul+i)+j));
            }
            printf("\n");
        }
    }
}
void take_input(int n, int r, int c, int arr[][10])
{
    printf("Enter the value of matrix %d: ", n);
    int i, j;
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            scanf("%d", (*(arr+i)+j));
        }
    }
}

/*
// add two matrices
#include<stdio.h>
#define MAX_SIZE 100
int main()
{
    int m1[MAX_SIZE][MAX_SIZE], m2[MAX_SIZE][MAX_SIZE], sum[MAX_SIZE][MAX_SIZE], i, j, r, c;
    printf("Enter the number of row & column: ");
    scanf("%d %d",&r,&c);
    printf("Enter the element of 1st matric: ");
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            scanf("%d", &m1[i][j]);
        }
    }
    printf("Enter the element of 2nd matric: ");
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            scanf("%d", &m2[i][j]);
        }
    }
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            sum[i][j] = *(*(m1+i)+j) + *(*(m2+i)+j);
        }
    }
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            printf("%d ",*(*(sum+i)+j));
        }
        printf("\n");
    }
    return 0;
}
*/
