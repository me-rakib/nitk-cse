#include<stdio.h>
#include<string.h>
#define MAX_SIZE 1000
int main() 
{
    char str[MAX_SIZE];
    printf("Enter your string: ");
    scanf("%[^\n]%*c", str);
    int i, len, res=1;
    len = strlen(str);   //length of string
    for(i=0; i<len; i++) 
    {
        if(str[i] != str[len-1-i])  
        {
            res = 0;
            break;
        }
    }
    if(res==1)
    {
        printf("Palindrome");
    }
    else 
    {
        printf("Not Palindrome");
    }
    return 0;
}