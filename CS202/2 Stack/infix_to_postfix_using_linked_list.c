#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

struct Node
{
    char data;
    struct Node *next;
};

struct Node *top = NULL;
struct Node *postfix = NULL;

void push(char ch);
char pop();
int is_operator(char ch);
int precedence(char ch);
void convert(char *infix);
struct Node *insert(struct Node *head, char ch);
void print(struct Node *head);

int main()
{
    char infix[MAX_SIZE] = "(A+B^C)*D+E^5";
    printf("Infix: %s\n", infix);
    convert(infix);
    printf("Postfix: ");
    print(postfix);
}

void convert(char *infix)
{
    int i, len = strlen(infix);
    char ch;

    for (i = 0; i < len; i++)
    {
        ch = infix[i];
        if (is_operator(ch) == 0)
        {
            postfix = insert(postfix, ch);
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
                    while (top->data != '(')
                    {
                        postfix = insert(postfix, pop());
                    }
                    pop();
                }
                else
                {
                    if (precedence(ch) > precedence(top->data))
                    {
                        push(ch);
                    }
                    else
                    {
                        while (precedence(ch) <= precedence(top->data))
                        {
                            postfix = insert(postfix, pop());
                        }
                        push(ch);
                    }
                }
            }
        }
    }
    while (top != NULL)
    {
        postfix = insert(postfix, pop());
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

void push(char ch)
{
    struct Node *newP = (struct Node *)malloc(sizeof(struct Node));
    newP->data = ch;
    newP->next = top;
    top = newP;
}

char pop()
{
    char ch = top->data;
    struct Node *temp = top;
    top = temp->next;
    free(temp);
    temp = NULL;
    return ch;
}

struct Node *insert(struct Node *head, char ch)
{
    struct Node *newP = (struct Node *)malloc(sizeof(struct Node));
    newP->data = ch;
    newP->next = NULL;
    if (head == NULL)
    {
        head = newP;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newP;
    }
    return head;
}

void print(struct Node *head)
{
    while (head != NULL)
    {
        printf("%c", head->data);
        head = head->next;
    }
    printf("\n");
}