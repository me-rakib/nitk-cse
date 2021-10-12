#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    return stack[top--];
}

int isOperator(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
    case '(':
    case ')':
        return 1;
    default:
        return 0;
    }
}

int precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 3;
    case '^':
        return 4;
    default:
        return 1; // if (, ), or empty
    }
}

void convert(char infix[], char postfix[])
{
    int i, len = strlen(infix), j = 0;
    char ch;
    for (i = 0; i < len; i++)
    {
        ch = infix[i];
        if (isOperator(ch) == 0)
        {
            postfix[j] = ch;
            j++;
        }
        else
        {
            if (ch == '(')
            {
                push(ch);
            }
            else
            {
                if (ch == ')')
                {
                    while (stack[top] != '(')
                    {
                        postfix[j] = pop();
                        j++;
                    }
                    pop(); //remove (
                }
                else
                {
                    if (ch == '^')
                    {
                        printf("HELLO\n");
                        while (precedence(ch) <= precedence(stack[top]))
                        {
                            postfix[j] = pop();
                            j++;
                        }
                        push(ch);
                    }

                    else if (precedence(ch) > precedence(stack[top]))
                    {
                        push(ch);
                    }
                    else
                    {
                        while (precedence(ch) < precedence(stack[top]))
                        {
                            postfix[j] = pop();
                            j++;
                        }
                        push(ch);
                    }
                }
            }
        }
    }
    while (top != -1)
    {
        postfix[j] = pop();
        j++;
    }
    postfix[j] = '\0';
}

void reverse(char *ch)
{
    int i = 0, j = strlen(ch) - 1;
    char temp;
    while (i < j)
    {
        temp = ch[i];
        ch[i] = ch[j];
        ch[j] = temp;
        i++;
        j--;
    }
}

void change_parenthesis(char *ch)
{
    int len = strlen(ch), i;
    for (i = 0; i < len; i++)
    {
        if (ch[i] == '(')
        {
            ch[i] = ')';
        }
        else if (ch[i] == ')')
        {
            ch[i] = '(';
        }
    }
}

int main()
{
    char infix[MAX_SIZE] = "(A+B^C)*D+E^5", postfix[MAX_SIZE];
    reverse(infix);
    change_parenthesis(infix);
    convert(infix, postfix);
    printf("Infix: %s\n", infix);
    reverse(postfix);
    printf("Postfix: %s\n", postfix);
    return 0;
}
