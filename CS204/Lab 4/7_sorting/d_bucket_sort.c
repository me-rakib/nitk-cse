/*
1. get max and min value
2. store 0 to all the bucket
3. if bucket[arr[i]] found then do ++
4. copy the position of bucket into main array
*/

#include <stdio.h>

int comparison = 0;

int getMax(int *arr, int size)
{
    int i, max = arr[0];
    for (i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

int getMin(int *arr, int size)
{
    int i, min = arr[0];
    for (i = 1; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
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

void bucketSort(int *arr, int size)
{
    int i, max = getMax(arr, size), min = getMin(arr, size);
    int bucket[max];
    for (i = min; i <= max; i++)
    {
        bucket[i] = 0;
    }
    for (i = 0; i < size; i++)
    {
        bucket[arr[i]]++;
    }
    int ind = 0;
    for (i = min; i <= max; i++)
    {
        while (bucket[i] > 0)
        {
            arr[ind++] = i;
            bucket[i]--;
            comparison++;
        }
    }
}

int main()
{
    int arr[] = {54, 12, 84, 57, 69, 41, 9, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    bucketSort(arr, n);
    print(arr, n);
    printf("\nTotal comparison = %d", comparison);
    return 0;
}