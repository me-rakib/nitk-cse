#include <stdio.h>
int main()
{
    FILE *fp, *even, *odd;
    int num;
    fp = fopen("DATA.txt", "r");
    even = fopen("EVEN.txt", "w");
    odd = fopen("ODD.txt", "w");
    if (fp == NULL || even == NULL || odd == NULL)
    {
        printf("An error occured");
    }
    else
    {
        while (!feof(fp))
        {
            fscanf(fp, "%d", &num);
            if (num % 2 == 0)
            {
                fprintf(even, "%d\n", num);
            }
            else
            {
                fprintf(odd, "%d\n", num);
            }
        }
    }
    fclose(fp);
    fclose(even);
    fclose(odd);
    return 0;
}