#include <stdio.h>
#include <stdlib.h>

void swipe(int *data1, int *data2)
{
    int temp;
    temp = *data1;
    *data1 = *data2;
    *data2 = temp;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int i, j, n, *arr;
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        scanf("%d", (arr + i));
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swipe(&arr[j], &arr[j + 1]);
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("%d ", *(arr + i));
    }
    return 0;
}