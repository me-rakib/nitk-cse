#include <stdio.h>
#include <stdlib.h>

void print(int n, int *arr);
void upper_row_map(int n, int **main_arr, int *arr_to_store);
void upper_col_map(int n, int **main_arr, int *arr_to_store);
void lower_row_map(int n, int **main_arr, int *arr_to_store);
void lower_col_map(int n, int **main_arr, int *arr_to_store);

int main()
{
    //redirecting input and output
    freopen("input_2.txt", "r", stdin);
    freopen("output_2.txt", "w", stdout);

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

    //mapping and printing
    printf("Upper Triangle: \n");
    upper_row_map(n, main_array, store_up_row_map);
    printf("Row-major: ");
    print(size_of_map_arr, store_up_row_map);

    printf("\nColumn-major: ");
    upper_col_map(n, main_array, store_up_col_map);
    print(size_of_map_arr, store_up_col_map);

    printf("\n\nLower Triangle: ");
    lower_row_map(n, main_array, store_lw_row_map);
    printf("\nRow-major: ");
    print(size_of_map_arr, store_lw_row_map);

    printf("\nColumn-major: ");
    lower_col_map(n, main_array, store_lw_col_map);
    print(size_of_map_arr, store_lw_col_map);


    return 0;
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
        for (j = i; j <n; j++)
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