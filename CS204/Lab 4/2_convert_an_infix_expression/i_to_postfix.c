/*

Traverse till last character -
1. if ch is not an operator then directly print
2. if ( is found push to stack
3. if ) is found pop till ( is found
4. if precedence(ch) > precedence(stack[top]) then push
5. else while precedence(ch) <= precedence(stack[top]) pop 

*/


#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

int top = -1;
int stack[MAX_SIZE];

int push(int ch)
{
    stack[++top] = ch;
}

int pop()
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

void convert(char *infix, char *postfix)
{
    int i, j = 0, len = strlen(infix);
    char ch;
    for (i = 0; i < len; i++)
    {
        ch = infix[i];
        if (isOperator(ch) == 0)
        {
            postfix[j++] = ch;
        }
        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            while (stack[top] != '(')
            {
                postfix[j++] = pop();
            }
            pop(); // remove (
        }
        else if (precedence(ch) > precedence(stack[top]))
        {
            push(ch);
        }
        else
        {
            while (precedence(ch) <= precedence(stack[top]))
            {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }
    while (top != -1)
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

int main()
{
    char infix[MAX_SIZE] = "(2+2^3)*4+5^5", postfix[MAX_SIZE];
    printf("Infix expression: %s\n", infix);
    convert(infix, postfix);
    printf("Postfix expression: %s", postfix);
    return 0;
}