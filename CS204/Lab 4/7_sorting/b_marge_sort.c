#include <stdio.h>
#include <stdlib.h>

int comparison = 0;

void print(int *arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void marge(int *arr, int *left, int leftCount, int *right, int rightCount)
{
    int i = 0, j = 0, k = 0;
    while (i < leftCount && j < rightCount)
    {
        if (left[i] < right[j])
        {
            arr[k++] = left[i++];
        }
        else
        {
            arr[k++] = right[j++];
        }
        comparison++;
    }
    while (i < leftCount)
    {
        arr[k++] = left[i++];
    }
    while (j < rightCount)
    {
        arr[k++] = right[j++];
    }
}

void margeSort(int *arr, int size)
{
    int i, mid, *left, *right;
    if (size < 2)
        return;
    mid = size / 2;
    left = (int *)malloc(mid * sizeof(int));
    right = (int *)malloc((size - mid) * sizeof(int));
    for (i = 0; i < mid; i++)
        left[i] = arr[i];
    for (i = mid; i < size; i++)
        right[i - mid] = arr[i];
    margeSort(left, mid);
    margeSort(right, size - mid);
    marge(arr, left, mid, right, size - mid);
    free(left);
    free(right);
}

int main()
{
    int arr[] = {6, 2, 3, 1, 9, 10, 15, 13, 12, 17};
    int size = sizeof(arr) / sizeof(arr[0]);
    margeSort(arr, size);
    print(arr, size);
    printf("\nTotal comparison = %d", comparison);
    return 0;
}