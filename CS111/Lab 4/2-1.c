#include<stdio.h>
#define MAX_SIZE 1000
int main() 
{
    char str[MAX_SIZE];
    printf("Enter a staring: ");
    scanf("%[^\n]%*c", str);  // take input until new line
    int i=0, len=0;
    while(str[i] != '\0')  //null character 
    {
        len++;
        i++;
    }
    printf("Length of string = %d", len);
    return 0;
}