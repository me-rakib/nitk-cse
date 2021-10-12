// implimentation of stack using linked list

#include<stdio.h>
#include<stdlib.h>

struct lifo {
    int data;
    struct lifo *next;
};
typedef struct lifo stack;

void create(stack **top)
{
    *top = NULL;
}

void push(stack **top, int data)
{
    stack *newP = (stack *)malloc(sizeof(stack));
    if(newP == NULL)
    {
        printf("Stack is full");
        exit(-1);
    }
    newP->data = data;
    newP->next = *top;
    *top = newP;
}

int pop(stack **top)
{
    int data;
    stack *temp;
    if(top == NULL)
    {
        printf("List is empty");
        exit(-1);
    }
    data = (*top)->data;
    temp = *top;
    *top = (*top)->next;
    free(temp);
    temp = NULL;
    return data;
}

int isEmpty(stack *top)
{
    if(top == NULL)
    {
        return 1;
    }
    return 0;
}

int main()
{
    stack *A, *B;
    create(&A);
    push(&A, 10);
    push(&A, 20);
    push(&A, 30);
    printf("%d ", pop(&A));
    printf("%d ", pop(&A));
    return 0;
}