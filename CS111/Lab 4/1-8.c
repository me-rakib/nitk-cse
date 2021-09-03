#include<stdio.h>
int main()
{
    int matrix[3][3], i,j, temp, size, row, col;
    printf("Enter entities for 3x3 matrix: ");
    for(i=0; i<3; i++) 
    {
        for(j=0; j<3; j++) 
        {
            scanf("%d",(*(matrix+i)+j));
        }
    }
    size = 3;
    for(row=0; row<size; row++)
    {
        col = row;
 
        temp = matrix[row][col];
        matrix[row][col] = matrix[row][(size-col) - 1];
        matrix[row][(size-col) - 1] = temp;
    }
    for(i=0; i<3; i++) 
    {
        for(j=0; j<3; j++) 
        {
            printf("%d ",*(*matrix+i)+j);
        }
        printf("\n");
    }
    return 0;
}

/*
#include <stdio.h>
int main()
{
    int matrix[3][3], i, j, temp;
    printf("Enter elements in matrix of size 3x3: ");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d", (*(matrix + i) + j));
        }
    }
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (i % 2 == 0)
            {
                temp = *(*(matrix + i) + j);
                *(*(matrix + i) + j) = *(*(matrix + i) + (j + 2));
                *(*(matrix + i) + (j + 2)) = temp;
            }
            break;
        }
    }
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", *(*(matrix + i) + j));
        }
        printf("\n");
    }
    return 0;
}

*/