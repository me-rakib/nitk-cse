#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fp_in, *fp_out;
    char line[100];
    fp_in = fopen("Input.txt", "r");
    fp_out = fopen("final.txt", "r+");
    if (fp_in == NULL || fp_out == NULL)
    {
        printf("An error occured");
        exit(1);
    }
    else
    {
        fseek(fp_out, 0, SEEK_END);
        while (!feof(fp_in))
        {
            fgets(line, 100, fp_in);
            fprintf(fp_out, "%s", line);
        }
    }
    fclose(fp_in);
    fclose(fp_out);
    return 0;
}