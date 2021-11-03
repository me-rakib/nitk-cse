/*
Algo:
Traverse - 
1. if operand, append to output
2. if '(' push to stack
3. if ')' pop and append till '('
4. if operator is found - 
precedence(ch) > precedence(stach[top]) -> push
while (precedence(ch) <= precedence(stach[top])) -> pop()


https://www.tutorialspoint.com/data_structures_algorithms/expression_parsing_using_statck.htm

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<math.h>
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
                    if (precedence(ch) > precedence(stack[top]))
                    {
                        push(ch);
                    }
                    else
                    {
                        while (precedence(ch) <= precedence(stack[top]))
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

int stack_int[MAX_SIZE];
int top_int = -1;

void push_int(int n)
{
    stack_int[++top_int] = n;
}

int pop_int()
{
    return stack_int[top_int--];
}

int evaluate(char *postfix)
{
    char ch;
    int i = 0, data1, data2;

    while (postfix[i] != '\0')
    {
        ch = postfix[i];
        if (isdigit(ch))
        {
            push_int(ch - '0'); // Push the operand
        }
        else
        {
            data2 = pop_int();
            data1 = pop_int();

            switch (ch)
            {
            case '+':
                push_int(data1 + data2);
                break;
            case '-':
                push_int(data1 - data2);
                break;
            case '*':
                push_int(data1 * data2);
                break;
            case '/':
                push_int(data1 / data2);
                break;
            case '^':
                push_int(pow(data1, data2));
                break;
            }
        }
        i++;
    }
    return stack_int[top_int];
}

int main()
{
    // char infix[MAX_SIZE] = "(A+B^C)*D+E^5", postfix[MAX_SIZE];
    char infix[MAX_SIZE] = "(2+2^3)*4+5^5", postfix[MAX_SIZE];
    convert(infix, postfix);
    printf("Infix: %s\n", infix);
    printf("Postfix: %s\n", postfix);
    printf("Result: %d\n", evaluate(postfix)); 
    return 0;
}