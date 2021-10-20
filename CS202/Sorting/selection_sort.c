#include <stdio.h>
#include <stdlib.h>

void swipe(int *data1, int *data2)
{
    int temp = *data1;
    *data1 = *data2;
    *data2 = temp;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int i, j, n, *arr, ind, temp;
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        scanf("%d", (arr + i));
    }
    for (i = 0; i < n - 1; i++)
    {
        ind = i;
        for (j = i; j < n; j++)
        {
            if (arr[ind] > arr[j])
            {
                ind = j;
            }
        }
        swipe(&arr[ind], &arr[i]);
    }
    for (i = 0; i < n; i++)
    {
        printf("%d ", *(arr + i));
    }
}