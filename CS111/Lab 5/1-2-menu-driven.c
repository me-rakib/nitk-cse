#include <stdio.h>
#include <string.h>

void find_len();
void copy_str();
void compare_str();

int main()
{
    int n;
    printf("1. Find the length of a string\n");
    printf("2. Copy a string to other\n");
    printf("3. Compare two string\n");
    printf("Enter 1, 2 or 3 to select fuction: ");
    scanf("%d ", &n);
    switch (n)
    {
    case 1:
        find_len();
        break;
    case 2:
        copy_str();
        break;
    case 3:
        compare_str();
        break;
    default:
        printf("Program closed");
    }
    return 0;
}

void find_len()
{
    int len = 0;
    char ch[100];
    printf("Enter your string: ");
    scanf("%[^\n]%*c", ch);
    while (ch[len] != '\0')
    {
        len++;
    }
    printf("Length of \"%s\" is %d", ch, len);
}

void copy_str()
{
    int len, i;
    char ch[100], ch2[100];
    printf("Enter string: ");
    fgets(ch, 100, stdin);
    len = strlen(ch) - 1;
    for (i = 0; i < len; i++)
    {
        ch2[i] = ch[i];
    }
    printf("Copied string \"%s\"", ch2);
}

void compare_str()
{
    int len1, len2, sm, i, res = 0;
    char ch[100], ch2[100];
    printf("Enter 1st string: ");
    fgets(ch, 100, stdin);
    printf("Enter 2nd string: ");
    fgets(ch2, 100, stdin);
    len1 = strlen(ch) - 1;
    len2 = strlen(ch2) - 1;
    sm = len1 < len2 ? len1 : len2;
    for (i = 0; i < sm; i++)
    {
        if (ch[i] == ch2[i])
        {
            res = 1;
        }
        else
        {
            res = 0;
            break;
        }
    }
    if (res == 1)
    {
        printf("Both are same");
    }
    else
    {
        printf("Diffrent String");
    }
}
