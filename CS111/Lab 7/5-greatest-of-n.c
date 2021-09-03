#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, i, temp;
    printf("Enter total element: ");
    scanf("%d", &n);
    int *arr;
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory not allocated");
        exit(0);
    }
    else
    {
        printf("Enter element: ");
        for (i = 0; i < n; i++)
        {
            scanf("%d", (arr + i));
        }
        temp = arr[0];
        for (i = 0; i < n; i++)
        {
            if (arr[i] > temp)
            {
                temp = arr[i];
            }
        }
    }
    free(arr);
    arr = NULL;
    printf("\nGreatest Number: %d", temp);
    return 0;
}