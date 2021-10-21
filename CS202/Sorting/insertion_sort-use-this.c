// insertion sort
#include <stdio.h>
#include <stdlib.h>

void swipe(int *d1, int *d2)
{
    int temp = *d1;
    *d1 = *d2;
    *d2 = temp;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int i, j, n, *A, temp;
    scanf("%d", &n);
    A = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        scanf("%d", (A + i));
    }

    for (i = 1; i < n; i++)
    {
        temp = A[i];
        j = i;
        while (j > 0 && A[j - 1] > temp)
        {
            A[j] = A[j - 1];
            j--;
        }
        A[j] = temp;
    }

    for (i = 0; i < n; i++)
    {
        printf("%d ", *(A + i));
    }
    return 0;
}