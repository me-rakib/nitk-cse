#include <stdio.h>

int main()
{
    int low = 0, high, search, mid, pos = -1;
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90}; // array must be sorted
    high = sizeof(arr) / sizeof(arr[0]);
    search = 50;

    // binary search
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == search)
        {
            pos = mid;
            break;
        }
        else if (arr[mid] < search)
        {
            low = mid + 1;
        }
        else if (arr[mid] > search)
        {
            high = mid - 1;
        }
    }

    if (pos == -1)
    {
        printf("Not found");
    }
    else
    {
        printf("%d found in %d", search, pos+1);
    }
    return 0;
}