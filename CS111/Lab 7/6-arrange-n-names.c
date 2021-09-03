#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, i, j;
    char **names, temp[100];
    printf("Enter total name: ");
    scanf("%d", &n);
    names = (char **)malloc(n * sizeof(char *));
    for (i = 0; i < n; i++)
    {
        names[i] = (char *)malloc(100 * sizeof(char));
    }
    printf("Enter name: ");
    getchar();
    for (i = 0; i < n; i++)
    {
        gets(names[i]);
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(names[i], names[j]) > 0) //sorting
            {
                strcpy(temp, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], temp);
            }
        }
    }
    printf("Names in alphabetical order: ");
    for (i = 0; i < n; i++)
    {
        printf("%s ", names[i]);
        free(names[i]);
        names[i] = NULL;
    }
    free(names);
    names = NULL;
    return 0;
}