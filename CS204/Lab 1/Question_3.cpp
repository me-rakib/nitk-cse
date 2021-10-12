#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
int main()
{
    freopen("input_3.txt", "r", stdin);
    freopen("output_3.txt", "w", stdout);
    int n, i, j, len, **matrix, **temp;
    char instruction[100], ins;
    cin >> n;

    // dynamically allocating memory
    matrix = (int **)calloc(n, sizeof(int *));
    temp = (int **)calloc(n, sizeof(int *));
    for (i = 0; i < n; i++)
    {
        matrix[i] = (int *)calloc(n, sizeof(int));
        temp[i] = (int *)calloc(n, sizeof(int));
    }

    //taking input
    for (i = 0; i < n; i++)
    {

        for (j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
    cin >> instruction;
    len = strlen(instruction);


    for (i = 0; i < len; i++)
    {
        ins = instruction[i];
        if (ins == 'R')
        {
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < n; j++)
                {
                    temp[i][j] = matrix[n - j - 1][i];  //rotating 90deg right
                }
            }
        }
        else if (ins == 'L')
        {
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < n; j++)
                {
                    temp[i][j] = matrix[j][n - i - 1];  //rotating 90deg left
                }
            }
        }

        // updating matrix 
        for (i = 0; i < n; i++)
        {

            for (j = 0; j < n; j++)
            {
                matrix[i][j] = temp[i][j];
            }
        }
    }

    // printing matrix
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    free(matrix);
    free(temp);
    return 0;
}