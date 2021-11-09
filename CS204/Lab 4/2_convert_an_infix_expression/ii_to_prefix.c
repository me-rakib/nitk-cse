/*
Algo -
1. reverse infix
2. shift ( with ) and ) with (
3. use infix to postfix methode with little modification 
    - for ^ use precedence(ch) <= precedence(stack[top])
    otherwise use precedence(ch) < precedence(stack[top])
4. reverse the result getting from 3
*/

#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

int top = -1;
char stack[MAX_SIZE];

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
        return 1; // for (, ) and empty
    }
}

void reverse(char *ch)
{
    int i = 0, len = strlen(ch) - 1;
    char temp;
    while (i < len)
    {
        temp = ch[i];
        ch[i] = ch[len];
        ch[len] = temp;
        i++;
        len--;
    }
}

void shift_parenthesis(char *ch)
{
    int i = 0;
    while (ch[i] != '\0')
    {
        if (ch[i] == '(')
        {
            ch[i] = ')';
        }
        else if (ch[i] == ')')
        {
            ch[i] = '(';
        }
        i++;
    }
}

void convert(char *infix, char *prefix)
{
    int i, j = 0, len = strlen(infix);
    char ch;
    for (i = 0; i < len; i++)
    {
        ch = infix[i];
        if (isOperator(ch) == 0)
        {
            prefix[j++] = ch;
        }
        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            while (stack[top] != '(')
            {
                prefix[j++] = pop();
            }
            pop(); // remove (
        }
        else if (ch == '^')
        {
            while (precedence(ch) <= precedence(stack[top]))
            {
                prefix[j++] = pop();
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
                prefix[j++] = pop();
            }
            push(ch);
        }
    }
    while (top != -1)
    {
        prefix[j++] = pop();
    }
    prefix[j] = '\0';
}

int main()
{
    char infix[MAX_SIZE] = "(20+2^3)*4+5^5", prefix[MAX_SIZE];
    printf("Infix expression: %s\n", infix);
    reverse(infix);
    shift_parenthesis(infix);
    convert(infix, prefix);
    reverse(prefix);
    printf("Prefix expression: %s\n", prefix);
    return 0;
}