// https://www.javatpoint.com/radix-sort

#include <stdio.h>

int getMax(int arr[], int n);
void radixSort(int *arr, int n);
void print(int *arr, int n);

int main()
{
    int arr[] = {90, 23, 101, 45, 65, 23, 67, 89, 34, 23};
    int n = sizeof(arr) / sizeof(arr[0]);
    radixSort(arr, n);
    print(arr, n);
    return 0;
}

void radixSort(int *arr, int n)
{
    int i, j, max = getMax(arr, n), divisor = 1, pass, NOP = 0, reminder;
    int bucket[n][n], bucket_count[n];
    while (max != 0)
    {
        NOP++;
        max /= 10;
    }
    for (pass = 0; pass < NOP; pass++)
    {
        for (i = 0; i < n; i++)
        {
            bucket_count[i] = 0;
        }
        for (i = 0; i < n; i++)
        {
            reminder = (arr[i] / divisor) % 10;
            bucket[reminder][bucket_count[reminder]] = arr[i];
            bucket_count[reminder]++;
        }
        int ind = 0;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < bucket_count[i]; j++)
            {
                arr[ind++] = bucket[i][j];
            }
        }
        divisor *= 10;
    }
}

int getMax(int *arr, int n)
{
    int i, max = arr[0];
    for (i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void print(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}