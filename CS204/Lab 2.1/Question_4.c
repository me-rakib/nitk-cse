#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void print(int n, int *arr);
void upper_row_map(int n, int **main_arr, int *arr_to_store);
void upper_col_map(int n, int **main_arr, int *arr_to_store);
void lower_row_map(int n, int **main_arr, int *arr_to_store);
void lower_col_map(int n, int **main_arr, int *arr_to_store);
bool symmetric(int n, int **main_arr);

int main()
{
    //redirecting input and output
    freopen("input_4.txt", "r", stdin);
    freopen("output_4.txt", "w", stdout);

    int n, i, j, **main_array, *store_up_row_map, *store_up_col_map, *store_lw_row_map, *store_lw_col_map, size_of_map_arr;
    scanf("%d", &n);

    //allocating memory dynamically
    main_array = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        main_array[i] = (int *)malloc(n * sizeof(int));
    }
    size_of_map_arr = (n * (n + 1)) / 2;
    store_up_row_map = (int *)malloc(size_of_map_arr * sizeof(int));
    store_up_col_map = (int *)malloc(size_of_map_arr * sizeof(int));
    store_lw_row_map = (int *)malloc(size_of_map_arr * sizeof(int));
    store_lw_col_map = (int *)malloc(size_of_map_arr * sizeof(int));

    //taking input
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", (*(main_array + i) + j));
        }
    }
    if (symmetric(n, main_array))
    {
        //mapping and printing
        upper_row_map(n, main_array, store_up_row_map);
        printf("Row-major: ");
        print(size_of_map_arr, store_up_row_map);

        printf("\n\t\t   ");
        upper_col_map(n, main_array, store_up_col_map);
        print(size_of_map_arr, store_up_col_map);

        lower_row_map(n, main_array, store_lw_row_map);
        printf("\nColumn-major: ");
        print(size_of_map_arr, store_lw_row_map);

        printf("\n\t\t\t  ");
        lower_col_map(n, main_array, store_lw_col_map);
        print(size_of_map_arr, store_lw_col_map);
    }
    else 
    {
        printf("This matrix is not symmetric");
    }

    return 0;
}

bool symmetric(int n, int **main_arr)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (*(*(main_arr + i) + j) != *(*(main_arr + j) + i))
            {
                return false;
            }
        }
    }
    return true;
}

void upper_row_map(int n, int **main_arr, int *arr_to_store)
{
    int i, j, k = 0;
    for (i = 0; i < n; i++)
    {
        for (j = i; j < n; j++)
        {
            *(arr_to_store + k) = *(*(main_arr + i) + j);
            k++;
        }
    }
}

void upper_col_map(int n, int **main_arr, int *arr_to_store)
{
    int i, j, k = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= i; j++)
        {
            *(arr_to_store + k) = *(*(main_arr + j) + i);
            k++;
        }
    }
}

void lower_row_map(int n, int **main_arr, int *arr_to_store)
{
    int i, j, k = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= i; j++)
        {
            *(arr_to_store + k) = *(*(main_arr + i) + j);
            k++;
        }
    }
}

void lower_col_map(int n, int **main_arr, int *arr_to_store)
{
    int i, j, k = 0;
    for (i = 0; i < n; i++)
    {
        for (j = i; j < n; j++)
        {
            *(arr_to_store + k) = *(*(main_arr + j) + i);
            k++;
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