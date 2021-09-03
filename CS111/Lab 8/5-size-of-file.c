#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fp;
    fp = fopen("DATA.txt", "r");
    if (fp == NULL)
    {
        printf("An error occured");
        exit(1);
    }
    else
    {
        fseek(fp, 0, SEEK_END); //moving pointer to end
        printf("Size = %ld bytes", ftell(fp));
    }
    fclose(fp);
    return 0;
}