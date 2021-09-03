#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fp;
    char ch;
    int count = 1;
    fp = fopen("DATA.txt", "r");
    if (fp == NULL)
    {
        printf("An error occured");
        exit(1);
    }
    else
    {
        while (!feof(fp))
        {
            ch = fgetc(fp);
            if (ch == '\n')
            {
                count++;
            }
        }
    }
    fclose(fp);
    printf("Total Line = %d", count);
    return 0;
}