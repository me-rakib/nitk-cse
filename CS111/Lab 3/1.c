#include<stdio.h>
int main() 
{
    char ch;
    printf("Enter character: ");
    scanf("%c",&ch);
    if((ch>='0') && (ch<='9'))   // number
    {
        printf("\nDigit\n");    
    }
    else if ((ch>='a')&&(ch<='z'))   //lowercase 
    {
        printf("\nLowercase\n");
    }
    else if ((ch>='A') && (ch<='Z'))  //uppercase
    {
        printf("\nUppercase\n");
    }
    else                          //otherwise special character
    {
        printf("\nSpecial Character\n");
    }
    return 0;
}