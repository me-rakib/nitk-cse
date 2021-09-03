// program to print the decimal, octal and hexadecimal value of a character 

#include<stdio.h>
int main()
{
    char ch;
    printf("Enter a character: ");
    scanf("%c",&ch);
    if(((ch>='a')&&(ch<='z'))||((ch>='A')&&(ch<='Z')))
    {
        printf("\nDecimal value: %d, Octal Value: %o, hexadecimal: %X\n",ch,ch,ch);
    }
    else
    {
        printf("Invalid Input");
    }
    return 0;
}
