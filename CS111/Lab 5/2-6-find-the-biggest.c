#include <stdio.h>

int find_big(int *arr, int size);
int main()
{
    int arr[] = {1, 2, 3, 4, 50, 6, 7, 8, 9, 10};
    int size, res;
    size = sizeof(arr) / sizeof(arr[0]);
    res = find_big(arr, size);
    printf("Biggest Element = %d", res);
    return 0;
}

int find_big(int *arr, int size)
{
    static int i = 0, big = -9999;
    if (i < size)
    {
        if (big < arr[i])
        {
            big = arr[i];
        }
        i++;
        return find_big(arr, size);
    }
    else 
    {
        return big;
    }
}