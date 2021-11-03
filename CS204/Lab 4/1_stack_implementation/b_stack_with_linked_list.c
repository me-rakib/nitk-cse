#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// function decleration
void push(int data);
void pop();
void display();
int isEmpty();

struct Node *head = NULL;

int main()
{
    push(10);
    push(11);
    push(12);
    pop();
    push(13);
    push(14);
    push(15);
    display();
    pop();
    display();
    return 0;
}

// inserting data into stack
void push(int data)
{
    struct Node *newP = (struct Node *)malloc(sizeof(struct Node));
    newP->data = data;
    newP->next = head;
    head = newP;
}

// removing data from stack
void pop()
{
    if (isEmpty())
    {
        printf("\nStack is empty\n");
    }
    else
    {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        temp = NULL;
    }
}

// printing data
void display()
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int isEmpty()
{
    return head == NULL ? 1 : 0;
}
