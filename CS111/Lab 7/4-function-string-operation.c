#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100
//functions
void concat();
void comp();
void length();
void copy();
void rev();
int main()
{
    int select;
    printf("Menu: \n");
    printf("1. Concatenation\n");
    printf("2. Comparison\n");
    printf("3. Length\n");
    printf("4. Copy\n");
    printf("5. Reverse\n");
    printf("Select Operation: ");
    scanf("%d", &select);
    switch (select)
    {
    case 1:
        concat();
        break;
    case 2:
        comp();
        break;
    case 3:
        length();
        break;
    case 4:
        copy();
        break;
    case 5:
        rev();
        break;
    default:
        printf("Wrong Input. Program Closed");
        break;
    }
    return 0;
}

void concat()
{
    char str1[MAX_SIZE], str2[MAX_SIZE];
    printf("Enter first string: ");
    gets(str1);
    gets(str1);
    printf("Enter second string: ");
    gets(str2);
    char *s1 = str1, *s2 = str2;
    while (*s1)
    {
        s1++;
    }
    while (*s2)
    {
        *s1 = *s2;
        s2++;
        s1++;
    }
    *s1 = '\0'; //string should end with \0
    printf("Concatenated string: %s", str1);
}

void comp()
{
    char str1[MAX_SIZE], str2[MAX_SIZE];
    printf("Enter first string: ");
    gets(str1);
    gets(str1);
    printf("Enter second string: ");
    gets(str2);
    char *s1 = str1, *s2 = str2;
    int cm = 0;
    while (*s1 && *s2)
    {
        if (*s1 != *s2)
        {
            cm = *s1 > *s2 ? 1 : 2;
        }
        s1++;
        s2++;
    }
    if (cm == 0)
    {
        printf("They both are same");
    }
    else if (cm == 1)
    {
        printf("%s is lexicographically smaller than %s", str2, str1);
    }
    else if (cm == 2)
    {
        printf("%s is lexicographically smaller than %s", str1, str2);
    }
}
void length()
{
    char str1[MAX_SIZE];
    printf("Enter string: ");
    gets(str1);
    gets(str1);
    char *s1 = str1;
    int len = 0;
    while (*s1)
    {
        len++;
        s1++;
    }
    printf("Length = %d", len);
}
void copy()
{
    char str1[MAX_SIZE], str2[MAX_SIZE];
    printf("Enter string: ");
    gets(str1);
    gets(str1);
    char *s1 = str1, *s2 = str2;
    while (*s1)
    {
        *s2 = *s1;
        s1++;
        s2++;
    }
    *s2 = '\0'; // string should end with \0
    printf("Copied string: %s", str2);
}
void rev()
{
    char str1[MAX_SIZE], temp;
    printf("Enter string: ");
    gets(str1);
    gets(str1);
    char *start = str1, *end = str1;
    int i, len = strlen(str1);
    end = end + (len - 1);
    for (i = 0; i < len / 2; i++)
    {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
    printf("Reversed string: %s", str1);
}