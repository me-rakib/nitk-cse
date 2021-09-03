#include<stdio.h>
#include<string.h>
#define MAX_SIZE 1000
int main() 
{
    char str[MAX_SIZE], temp;
    printf("Enter string: ");
    scanf("%[^\n]%*c", str);
    int i, len;
    len = strlen(str);
    printf("Output: ");
    for(i=0; i<len; i++) 
    {
        temp = *(str+i);
        if(temp>= 'a' && temp<='z') 
        {
            str[i] = temp-32;  // a-32 = A (ASCII)
        }
        else if(temp>= 'A' && temp<='Z') 
        {
            str[i] = temp+32;  // A+32 = a (ASCII)
        }
        printf("%c", *(str+i));
    }
    return 0;
}