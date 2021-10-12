#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void print(int n, int **board);
bool get_pos(int n, int **board, int col);
bool safe(int n, int **board, int row, int col);

int main()
{
    // redirecting input and output
    freopen("input_7.txt", "r", stdin);
    freopen("output_7.txt", "w", stdout);

    int n, **board, i;
    scanf("%d", &n);

    //allocating memory
    board = (int **)calloc(n, sizeof(int **));
    for (i = 0; i < n; i++)
    {
        board[i] = (int *)calloc(n, sizeof(int));
    }
    if (get_pos(n, board, 0) == false)
    {
        printf("No solution found");
    }
    else
    {
        print(n, board);
    }
}

//check whether position is under attacked or not
bool safe(int n, int **board, int row, int col)
{
    int i, j;
    for (i = 0; i < col; i++)
    {
        if (board[row][i])
        {
            return false;
        }
    }
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
        {
            return false;
        }
    }
    for (i = row, j = col; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j])
        {
            return false;
        }
    }
    return true;
}

//backtracking
bool get_pos(int n, int **board, int col)
{
    if (col >= n)
    {
        return true;
    }
    int i;
    for (i = 0; i < n; i++)
    {
        if (safe(n, board, i, col))
        {
            board[i][col] = 1;
            if (get_pos(n, board, col + 1))
            {
                return true;
            }
            board[i][col] = 0;
        }
    }
    return false;
}

//printing
void print(int n, int **board)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d  ", *(*(board + i) + j));
        }
        printf("\n");
    }
}