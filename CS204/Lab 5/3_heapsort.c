#include <stdio.h>
#include <stdlib.h>

// printing array element
void print(int *arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

// swaping element
void swap(int *n1, int *n2)
{
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

// healify function
void heapify(int *arr, int n, int i)
{
    int parent = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[parent])
    {
        parent = left;
    }
    if (right < n && arr[right] > arr[parent])
    {
        parent = right;
    }
    if (parent != i)
    {
        swap(&arr[i], &arr[parent]);
        heapify(arr, n, parent);
    }
}

// function for heapsort
void heap_sort(int *arr, int n)
{
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    for (i = n - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{
    int n, *arr, i;
    printf("Total element: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        printf("Enter element: ");
        scanf("%d", (arr + i));
    }

    printf("Before sorting: ");
    print(arr, n);

    heap_sort(arr, n);

    printf("\nHeapsort: ");
    print(arr, n);
}