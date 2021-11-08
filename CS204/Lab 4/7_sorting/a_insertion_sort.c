/*

1. Iterate all the elements
2. Compate the current value with previous
    - if prev > current then swape
    - else break the loop
    
*/

#include <stdio.h>

void swape(int *n1, int *n2)
{
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

int main()
{
    int i, j, total;
    int arr[] = {1, 9, 2, 7, 3, 8, 6, 4, 5};
    total = sizeof(arr) / sizeof(arr[0]);
    for (i = 0; i < total - 1; i++)
    {
        for (j = i + 1; j > 0; j--)
        {
            if (arr[j - 1] < arr[j])
            {
                break;
            }
            swape(&arr[j - 1], &arr[j]);
        }
    }

    for (i = 0; i < total; i++)
    {
        printf("%d ", arr[i]);
    }
}