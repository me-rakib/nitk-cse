/*
Algo - 
1. if found any digit push into stack
2. if any operator found pop two element from stack
3. based on operator do the same and push the result into stack 
4. if traversal is done return the last element from stack
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define MAX_SIZE 100

int top = -1;
int stack[MAX_SIZE];
void push(int digit)
{
    stack[++top] = digit;
}
int pop()
{
    return stack[top--];
}
int evaluation(char *postfix)
{
    int i = 0, data1, data2;
    char ch;
    while (postfix[i] != '\0')
    {
        ch = postfix[i];
        if (isdigit(ch))
        {
            push(ch - '0');
        }
        else
        {
            data2 = pop();
            data1 = pop();
            switch (ch)
            {
            case '+':
                push(data1 + data2);
                break;
            case '-':
                push(data1 - data2);
                break;
            case '*':
                push(data1 * data2);
                break;
            case '/':
                push(data1 / data2);
                break;
            case '^':
                push(pow(data1, data2));
                break;
            }
        }
        i++;
    }
    return stack[top];
}

int main()
{
    char postfix[MAX_SIZE] = "223^+4*55^+";
    printf("Result = %d", evaluation(postfix));
    return 0;
}