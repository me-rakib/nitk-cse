#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
} stack;

stack *top = NULL;

void push(int data) 
{
    stack *newP = (stack *)malloc(sizeof(stack));
    newP->data = data;
    newP->next = top;
    top = newP;
}

void pop()
{
    if(top == NULL)
    {
        printf("Nothing to remove\n");
        return;
    }
    stack *temp = top;
    top = temp->next;
    free(temp);
    temp = NULL;
}

void Top()
{
    printf("%d \n", top->data);
}

void print()
{
    stack *temp = top;
    printf("Stack elements: ");
    if(top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    push(10);
    print();
    push(5);
    print();
    push(7);
    print();
    Top();
    return 0;
}