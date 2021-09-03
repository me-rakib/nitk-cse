#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    FILE *fp;
    char name[20], line[50];
    int i, n, roll;
    fp = fopen("DATA.txt", "w");
    if (fp == NULL)
    {
        printf("An error occured");
        exit(1);
    }
    else
    {
        printf("Total student: ");
        scanf("%d", &n);
        for (i = 0; i < n; i++)
        {
            printf("Enter roll: ");
            scanf("%d", &roll);
            printf("Enter name: ");
            gets(name);
            fgets(name, 20, stdin);
            name[strcspn(name, "\n")] = 0;
            fprintf(fp, "%d %s\n", roll, name);
            printf("\n");
        }
        fclose(fp);
    }
    fp = fopen("DATA.txt", "r");
    if (fp == NULL)
    {
        printf("An error Occured");
    }
    else
    {
        i = 0;
        printf("Showing info from file: \n");
        while (i < n)
        {
            fgets(line, 50, fp);
            printf("%s", line);
            i++;
        }
        fclose(fp);
    }
    return 0;
}
