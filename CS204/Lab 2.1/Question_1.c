#include <stdio.h>
#include <stdlib.h>

void print(int n, int *arr);
void map(int n, int **main_arr, int *arr_to_store, char ch);

int main()
{
    //redirecting input and output
    freopen("input_1.txt", "r", stdin);
    freopen("output_1.txt", "w", stdout);

    int n, i, j, **main_array, *store_row_map, *store_col_map;
    scanf("%d", &n);

    //allocating memory dynamically
    main_array = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        main_array[i] = (int *)malloc(n * sizeof(int));
    }
    store_row_map = (int *)malloc(n * n * sizeof(int));
    store_col_map = (int *)malloc(n * n * sizeof(int));

    //taking input
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", (*(main_array + i) + j));
        }
    }

    //mapping and printing
    map(n, main_array, store_row_map, 'r');
    printf("Row-major: ");
    print(n * n, store_row_map);

    printf("\n\nColumn-major: ");
    map(n, main_array, store_col_map, 'c');
    print(n * n, store_col_map);
    return 0;
}

void map(int n, int **main_arr, int *arr_to_store, char ch)
{
    int i, j, k = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (ch == 'r')
            {
                *(arr_to_store + k) = *(*(main_arr + i) + j);
                k++;
            }
            else if (ch == 'c')
            {
                *(arr_to_store + k) = *(*(main_arr + j) + i);
                k++;
            }
        }
    }
}

void print(int n, int *arr)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", *(arr + i));
    }
}