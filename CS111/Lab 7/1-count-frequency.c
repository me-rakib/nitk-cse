#include <stdio.h>
#define MAX_SIZE 100
int main()
{
    char line[MAX_SIZE];
    char *ptr = line;
    printf("Enter line: ");
    gets(line);
    int i = 0, c, j;
    while (*(ptr + i))
    {
        c = 1;
        j = i + 1;
        if (*(ptr + i) != -1)
        {
            while (*(ptr + j))
            {
                if (*(ptr + i) == *(ptr + j))
                {
                    c++;
                    //replacing character with -1 which is already counted
                    *(ptr + j) = -1;
                }
                j++;
            }
            printf("'%c' = %d\n", *(ptr + i), c);
        }
        i++;
    }
    return 0;
}