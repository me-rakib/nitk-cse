#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, c, a[5][5], b[5][5];
    printf("Enter n: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }


    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if(i<j){
                printf("0 ");
            }
            else if(i>=j)
            {
                printf("%d ", i *(i-1)/2 + j-1);
            }
            else{
                printf("0 ");
            }
        }
        printf("\n");
    }
    return 0;
}
