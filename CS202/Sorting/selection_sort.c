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

    int i, j, n, *A, ind, temp;
    scanf("%d", &n);
    A = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        scanf("%d", (A + i));
    }
    for (i = 0; i < n - 1; i++)
    {
        ind = i;
        for (j = i; j < n; j++)
        {
            if (A[ind] > A[j])
            {
                ind = j;
            }
        }
        swipe(&A[ind], &A[i]);
    }
    for (i = 0; i < n; i++)
    {
        printf("%d ", *(A + i));
    }
}