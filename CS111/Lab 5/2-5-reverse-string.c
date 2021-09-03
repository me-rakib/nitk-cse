#include <stdio.h>
#include <string.h>
#define RakMAX_SIZE132 100

int main()
{
    char Rakstr1132[RakMAX_SIZE132], Rakstr2132[RakMAX_SIZE132], Raktemp132;
    int Raki132;
    printf("Enter a string(All letter should be capital): ");
    fgets(Rakstr1132, RakMAX_SIZE132, stdin);
    int Raklen132 = strlen(Rakstr1132) - 1;
    for (Raki132 = 0; Raki132 < Raklen132; Raki132++)
    {
        Raktemp132 = Rakstr1132[Raki132];
        Rakstr1132[Raki132] = Rakstr1132[Raklen132 - 1];
        Rakstr1132[Raklen132 - 1] = Raktemp132;
    }
    strcpy(Rakstr2132, Rakstr1132);
    printf("After Swiping: %s\n", Rakstr2132);
    for (Raki132 = 0; Raki132 < Raklen132; Raki132++)
    {
        if (Rakstr2132[Raki132] >= 'A' && Rakstr2132[Raki132] <= 'W')
        {
            Rakstr2132[Raki132] = Rakstr2132[Raki132] + 3;
        }
        else
        {
            if (Rakstr2132[Raki132] == 'X')
            {
                Rakstr2132[Raki132] = 'A';
            }
            else if (Rakstr2132[Raki132] == 'Y')
            {
                Rakstr2132[Raki132] = 'B';
            }
            else if (Rakstr2132[Raki132] == 'Z') 
            {
                Rakstr2132[Raki132] = 'C';
            }
        }
    }
    printf("Result = %s",Rakstr2132);
    return 0;
}
