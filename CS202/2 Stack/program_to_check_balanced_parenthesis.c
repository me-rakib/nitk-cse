// with this code will check whether a string's parenthesis is balanced or not

#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

void push(char *arr, char c, int *top)
{
    *(arr+(++(*top))) = c;
}

void pop(char *arr, char c, int *top)
{
    if (c == ')')
    {
        if (*(arr+(*top)) == '(')
        {
            (*top)--;
        }
    }
    else if (c == '}')
    {
        if (*(arr+(*top)) == '{')
        {
            (*top)--;
        }
    }
    else if (c == ']')
    {
        if (*(arr+(*top)) == '[')
        {
            (*top)--;
        }
    }
}

void display(char *arr, int *top)
{
    int i;
    if ((*top) == -1)
    {
        printf("Balanced ");
    }
    else
    {
        printf("Remaining: ");
        for (i = 0; i < (*top); i++)
        {
            printf("%c ", arr[i]);
        }
    }
}

int main()
{
    int top = -1, i, len;
    char arr[MAX_SIZE], str[MAX_SIZE], c;
    printf("Enter string with parenthesis: ");
    fgets(str, MAX_SIZE, stdin);
    str[strcspn(str, "\n")] = 0;
    len = strlen(str);
    for (i = 0; i < len; i++)
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            c = str[i];
            push(arr, c, &top);
        }
        else if (str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
            c = str[i];
            pop(arr, c, &top);
        }
    }
    display(arr, &top);
    return 0;
}