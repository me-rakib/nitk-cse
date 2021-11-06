#include <stdio.h>

int main()
{
    int i, total, search, pos = -1;
    int arr[] = {1, 7, 2, 3, 4, 5, 6, 8, 9, 10};
    total = sizeof(arr) / sizeof(arr[0]);
    search = 7;

    // linear search
    for (i = 0; i < total; i++)
    {
        if (search == arr[i])
        {
            pos = i;
            break;
        }
    }
    if (pos != -1)
    {
        printf("%d found in position %d", search, pos + 1);
    }
    else
    {
        printf("Not found");
    }
    return 0;
}