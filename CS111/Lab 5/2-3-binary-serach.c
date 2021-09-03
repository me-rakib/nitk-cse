#include <stdio.h>

int binary_search(int *arr, int low, int up, int srch);
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size, search, res;
    size = sizeof(arr) / sizeof(arr[0]);
    search = 6;
    res = binary_search(arr, 0, size, search);
    res == -1 ? printf("Not Found") : printf("Found in pos %d", res + 1);
    return 0;
}

int binary_search(int *arr, int low, int up, int srch)
{
    if (low <= up)
    {
        int mid = (low + up) / 2;
        if (arr[mid] == srch)
        {
            return mid;
        }
        else if (arr[mid] < srch)
        {
            binary_search(arr, mid + 1, up, srch);
        }
        else
        {
            binary_search(arr, low, mid - 1, srch);
        }
    }
    else
    {
        return -1;
    }
}