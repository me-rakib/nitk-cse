#include <stdio.h>
#include <stdlib.h>
int main()
{
    freopen("input_1.txt", "r", stdin);
    freopen("output_1.txt", "w", stdout);

    int n, i, j, **arr;
    scanf("%d", &n);

    //dynamically allocating memory
    arr = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
    }

    //taking input
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", (*(arr + i) + j));
        }
    }

    //printing 
    printf("Lower Triangle: \n");
    for (i = 1; i < n; i++)
    {
        for (j = 0; j < i; j++)
        {
            printf("%d ", *(*(arr + i) + j));
        }
        printf("\n");
    }

    printf("\nUpper Triangle: \n");
    for (i = 0; i < n-1; i++)
    {
        for(j=0; j<i; j++) 
        {
            printf("  "); //printing space
        }
        for (j = i+1; j < n; j++)
        {
            printf("%d ", *(*(arr + i) + j));
        }
        printf("\n");
    }
    return 0;
}