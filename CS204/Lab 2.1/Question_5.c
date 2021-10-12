/*
Total element of a tridiagonal element is 3r-2 
For diagonal: 
Lower: A[i-1];
Middle: A[r+i-1];
Upper: A[2*r+i-1];

Reference: http://twostack.blogspot.com/2017/02/tri-diagonal-matrix.html



*/

#include <stdio.h>
#include <stdlib.h>

void get_row_major(int r, int *store, int **arr);
void get_col_major(int r, int *store, int **arr);
void get_diagonal_wise(int r, int *store, int **arr);
void print(int size, int *store);

int main()
{
    //redirecting input and output
    freopen("input_5.txt", "r", stdin);
    freopen("output_5.txt", "w", stdout);

    int r, c, i, j, k = 0, **arr, *store_row, *store_col, *store_dia, size;
    scanf("%d %d", &r, &c);

    size = 3 * r - 2;  //size of 1d array

    //allocating memory
    arr = (int **)malloc(r * sizeof(int *));
    store_row = (int *)malloc(size * sizeof(int));
    store_col = (int *)malloc(size * sizeof(int));
    store_dia = (int *)malloc(size * sizeof(int));

    //taking input
    for (i = 0; i < r; i++)
    {
        arr[i] = (int *)malloc(c * sizeof(int));
        for (j = 0; j < c; j++)
        {
            scanf("%d", (*(arr + i) + j));
        }
    }

    //getting desired 1d array
    get_row_major(r, store_row, arr);
    get_col_major(r, store_col, arr);
    get_diagonal_wise(r, store_dia, arr);

    //printing
    printf("Row major: ");
    print(size, store_row);

    printf("\nCol major: ");
    print(size, store_col);

    printf("\nDiagonal wise: ");
    print(size, store_dia);

    return 0;
}

void get_row_major(int r, int *store, int **arr)
{
    int i, j, k = 0;
    for (i = 0; i < r; i++)
    {
        if (i == 0)
        {
            for (j = 0; j < 2; j++)
            {
                *(store + k) = *(*(arr + i) + k);
                k++;
            }
        }
        else if (i == r - 1)
        {
            for (j = i - 1; j < i + 1; j++)
            {
                *(store + k) = *(*(arr + i) + j);
                k++;
            };
        }
        else
        {
            for (j = i - 1; j < i + 2; j++)
            {
                *(store + k) = *(*(arr + i) + j);
                k++;
            }
        }
    }
}

void get_col_major(int r, int *store, int **arr)
{
    int i, j, k = 0;
    for (i = 0; i < r; i++)
    {
        if (i == 0)
        {
            for (j = 0; j < 2; j++)
            {
                *(store + k) = *(*(arr + k) + i);
                k++;
            }
        }
        else if (i == r - 1)
        {
            for (j = i - 1; j < i + 1; j++)
            {
                *(store + k) = *(*(arr + j) + i);
                k++;
            };
        }
        else
        {
            for (j = i - 1; j < i + 2; j++)
            {
                *(store + k) = *(*(arr + j) + i);
                k++;
            }
        }
    }
}

void get_diagonal_wise(int r, int *store, int **arr)
{
    int i, j;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < r; j++)
        {
            switch (i - j)
            {
            case 1:    //lower
                *(store + i - 1) = *(*(arr + i) + j);
                break;
            case 0:     //middle
                *(store + r + i - 1) = *(*(arr + i) + j);
                break;
            case -1:     //upper
                *(store + 2 * r + i - 1) = *(*(arr + i) + j);
                break;
            }
        }
    }
}

void print(int size, int *store)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", *(store + i));
    }
}