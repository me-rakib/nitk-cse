/*
Algo:
1. Reverse the whole string
2. Replace '(' with ')' and ')' with '('
3. With little modification use postfix algo to convert
    modification: for ^ only use precendence(ch) <= precedence(stack[top]), otherwise use precendence(ch) < precedence(stack[top])
4. Again reverse 
5. Print
*/


#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;
void push(char ch);
char pop();
void reverse(char *ch);
void shift_parenthesis(char *ch);
void convert(char *infix, char *prefix);
int is_operator(char ch);
int precedence(char ch);

int main()
{
    char infix[MAX_SIZE] = "(A+B^C)*D+E^5", prefix[MAX_SIZE];
    printf("Infix: %s\n", infix);
    reverse(infix);
    shift_parenthesis(infix);
    convert(infix, prefix);
    reverse(prefix);
    printf("Prefix: %s", prefix);
}

void convert(char *infix, char *prefix)
{
    int i, len = strlen(infix), j = 0;
    char ch;
    for (i = 0; i < len; i++)
    {
        ch = infix[i];
        if (is_operator(ch) == 0)
        {
            prefix[j] = ch;
            j++;
        }
        else
        {
            if (ch == '(')
            {
                push(ch);
            }
            else if (ch == ')')
            {
                while (stack[top] != '(')
                {
                    prefix[j] = pop();
                    j++;
                }
                pop(); // remove (
            }
            else if (ch == '^')
            {
                while (precedence(ch) <= precedence(stack[top]))
                {
                    prefix[j] = pop();
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
                    prefix[j] = pop();
                    j++;
                }
                push(ch);
            }
        }
    }
    while (top != -1)
    {
        prefix[j] = pop();
        j++;
    }
    prefix[j] = '\0';
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
        return 1; // for (, ) and empty stack
    }
}

int is_operator(char ch)
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

void reverse(char *ch)
{
    int low = 0, up = strlen(ch) - 1;
    char temp;
    while (low < up)
    {
        temp = ch[low];
        ch[low] = ch[up];
        ch[up] = temp;
        low++;
        up--;
    }
}

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    return stack[top--];
}
