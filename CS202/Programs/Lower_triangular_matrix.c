#include <stdio.h>
#include<stdlib.h>

void get_input(int n, int **arr);
void print_output(int n, int **arr);

int main()
{
    int n, **arr, i;
    printf("Enter n: ");
    scanf("%d", &n);
    arr = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
    }
    get_input(n, arr);
    print_output(n, arr);
    return 0;
}

void get_input(int n, int **arr)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", (*(arr + i) + j));
        }
    }
}

void print_output(int n, int **arr)
{
    int i, j, *temp, k=0,x;
    x = (n*(n+1))/2;
    temp = (int *)malloc(x * sizeof(int));
    for(i=0; i<n; i++) 
    {
        for(j=i; j<n; j++) 
        {
            *(temp+k) = *(*(arr+j)+i);
            k++;
        }
    }
    printf("\nBy row: ");
    for(i=0; i<x; i++) 
    {
        printf("%d ", *(temp+i));
    }
}
