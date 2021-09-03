#include <stdio.h>
int main()
{
    FILE *fp_in, *fp_out;
    char line[50];
    fp_in = fopen("Input.txt", "r");
    fp_out = fopen("Output.txt", "w");

    if (fp_in == NULL || fp_out == NULL)
    {
        printf("An error occured");
    }
    else
    {
        while (!feof(fp_in))
        {
            fgets(line, 50, fp_in);
            fprintf(fp_out, "%s", line);
        }
    }
    fclose(fp_in);
    fclose(fp_out);
    return 0;
}