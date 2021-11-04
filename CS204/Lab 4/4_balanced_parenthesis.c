// Balanced parenthesis with linked list
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

struct Node
{
    char ch;
    struct Node *next;
};

// function decleration
void push(char ch);
char pop();
int check_balanced(char *exp);
int match(char ch);

struct Node *head = NULL;

int main()
{
    char exp[MAX_SIZE] = "[()]";
    if (check_balanced(exp))
    {
        printf("\nBalanced\n");
    }
    else
    {
        printf("\nNot balanced\n");
    }
    return 0;
}

// function to match
int match(char ch)
{
    char temp = pop();
    if (temp == '(' && ch == ')')
    {
        return 1;
    }
    else if (temp == '{' && ch == '}')
    {
        return 1;
    }
    else if (temp == '[' && ch == ']')
    {
        return 1;
    }
    return 0;
}

// function for balanced parenthesis
int check_balanced(char *exp)
{
    int i = 0;
    char ch;
    while (exp[i] != '\0')
    {
        ch = exp[i];
        if (ch == '(' || ch == '{' || ch == '[')
        {
            push(ch);
        }
        else
        {
            if (!match(ch))
            {
                return 0;
            }
        }
        i++;
    }
    return 1;
}

void push(char ch)
{
    struct Node *newP = (struct Node *)malloc(sizeof(struct Node));
    newP->ch = ch;
    newP->next = head;
    head = newP;
}

char pop()
{
    struct Node *temp = head;
    char ch = temp->ch;
    head = temp->next;
    free(temp);
    temp = NULL;
    return ch;
}

// Balanced parenthesis with array

// #include <stdio.h>
// #define MAX_SIZE 100

// int top = -1;
// char stack[MAX_SIZE];

// void push(char ch)
// {
//     stack[++top] = ch;
// }

// char pop()
// {
//     return stack[top--];
// }

// int match(char ch)
// {
//     char temp = pop();
//     if (temp == '(' && ch == ')')
//     {
//         return 1;
//     }
//     else if (temp == '{' && ch == '}')
//     {
//         return 1;
//     }
//     else if (temp == '[' && ch == ']')
//     {
//         return 1;
//     }
//     return 0;
// }

// int check_balanced(char *exp)
// {
//     int i = 0;
//     char ch;
//     while (exp[i] != '\0')
//     {
//         ch = exp[i];
//         if (ch == '(' || ch == '{' || ch == '[')
//         {
//             push(ch);
//         }
//         else
//         {
//             if (!match(ch))
//             {
//                 return 0;
//             }
//         }
//         i++;
//     }
//     return 1;
// }

// int main()
// {
//     char exp[MAX_SIZE] = "[(])";
//     if(check_balanced(exp))
//     {
//         printf("\nBalanced\n");
//     }
//     else
//     {
//         printf("\nNot balanced\n");
//     }
//     return 0;
// }