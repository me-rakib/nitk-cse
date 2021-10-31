// bucket sort
#include <stdio.h>

int getMax(int arr[], int n)
{
    int i, max = arr[0];
    for (i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void bucketSort(int *arr, int n)
{
    int i, max = getMax(arr, n);
    int bucket[max];
    for (i = 0; i <= max; i++)
    {
        bucket[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        bucket[arr[i]]++;
    }
    int ind = 0;
    for (i = 0; i <= max; i++)
    {
        while (bucket[i] > 0)
        {
            arr[ind++] = i;
            bucket[i]--;
        }
    }
}

void print(int *arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int arr[] = {54, 12, 84, 57, 69, 41, 9, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    bucketSort(arr, n);
    print(arr, n);
    return 0;
}