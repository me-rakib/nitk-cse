/*
1. Get max num and calculate number of digit
2. traverse n(n is from 1) times
    - initialize every array of bucket count with 0
    - from 0 to total element of array
        - calculate reminder
        - store it into bucket
        - bucket_count[reminder]++
    - update main array
    - update divisior by * 10
*/

#include <stdio.h>

int getMax(int *arr, int size)
{
    int i, max = arr[0];
    for (i = 1; i <size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void print(int *arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void radixSort(int *arr, int size)
{
    int i, j, k, max = getMax(arr, size), divisor = 1, reminder, NOP = 0;
    int bucket[size][size], bucket_count[size];
    while (max != 0)
    {
        NOP++;
        max /= 10;
    }
    for (i = 0; i < NOP; i++)
    {
        for (j = 0; j < size; j++)
        {
            bucket_count[j] = 0;
        }
        for(j=0; j<size; j++)
        {
            reminder = (arr[j] / divisor) % 10;
            bucket[reminder][bucket_count[reminder]] = arr[j];
            bucket_count[reminder]++;
        }
        int ind = 0;
        for(j=0; j<size; j++)
        {
            for(k=0; k<bucket_count[j]; k++)
            {
                arr[ind++] = bucket[j][k];
            }
        }
        divisor *= 10;
    }
}

int main()
{
    int arr[] = {90, 23, 101, 45, 65, 23, 67, 89, 34, 23};
    int n = sizeof(arr) / sizeof(arr[0]);
    radixSort(arr, n);
    print(arr, n);
    return 0;
}