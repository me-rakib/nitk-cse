#include <stdio.h>

void swape(int *n1, int *n2)
{
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
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

int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int j, i = low-1;
    for(j=low; j<high; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swape(&arr[i], &arr[j]);
        }
    }
    swape(&arr[i+1], &arr[high]);
    return (i+1);
}

void quickSort(int *arr, int low, int high)
{
    if(low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, size-1);
    print(arr, size);
    return 0;
}