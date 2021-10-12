#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, c, a[5][5];
    printf("Enter n: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            switch(i-j) {
                case 1:
                    printf("i= %d j = %d %d ",i,j, i-2);
                    break;
                case 0:
                    printf("i= %d j = %d %d ",i,j, n+i-2);
                    break;
                case -1:
                    printf("i= %d j = %d %d ",i,j, 2*n+i-2);
                    break;
            }
        }
        printf("\n");
    }
    return 0;
}
