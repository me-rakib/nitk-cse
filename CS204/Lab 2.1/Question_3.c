#include <stdio.h>
#include <stdlib.h>
int main()
{
    //redirecting input output
    freopen("input_3.txt", "r", stdin);
    freopen("output_3.txt", "w", stdout);

    int r, c, i, j, k = 0, size = 0, **main_array, **sparse_matrix;
    scanf("%d %d", &r, &c);

    //allocating memory
    main_array = (int **)malloc(r * sizeof(int **));
    for (i = 0; i < r; i++)
    {
        main_array[i] = (int *)malloc(c * sizeof(int));
    }

    //taking input
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", (*(main_array + i) + j));
        }
    }

    //calculating total element without 0
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (*(*(main_array + i) + j) != 0)
            {
                size++;
            }
        }
    }

    //allocating memory for new array
    sparse_matrix = (int **)malloc(3 * sizeof(int *));
    for (i = 0; i < 3; i++)
    {
        sparse_matrix[i] = (int *)malloc(size * sizeof(int));
    }

    //storing data to new array
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (*(*(main_array + i) + j) != 0)
            {
                *(*(sparse_matrix + 0) + k) = i;
                *(*(sparse_matrix + 1) + k) = j;
                *(*(sparse_matrix + 2) + k) = *(*(main_array + i) + j);
                k++;
            }
        }
    }

    //printing data from new array
    for (i = 0; i < 3; i++)
    {
        switch (i)
        {
        case 0:
            printf("Row:   ");
            break;
        case 1:
            printf("Col:   ");
            break;
        case 2:
            printf("Value: ");
            break;
        }
        for (j = 0; j < size; j++)
        {
            printf("%d ", *(*(sparse_matrix + i) + j));
        }
        printf("\n");
    }

    return 0;
}