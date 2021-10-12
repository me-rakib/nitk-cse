// implimentation of stack using array

#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

struct lifo {
    int arr[MAX_SIZE];
    int top;
};
typedef struct lifo stack;

void create(stack *s)
{
    s->top = -1;
}

void push(stack *s, int data)
{
    if(s->top == MAX_SIZE-1)
    {
        printf("Stack overflow");
        exit(-1);
    }
    s->top++;
    s->arr[s->top] = data;
}

int pop(stack *s)
{
    if (s->top == -1)
    {
        printf("Stack Underflow");
        exit(-1);
    }
    return s->arr[s->top--];
}

int isEmpty(stack *s)
{
    if(s->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(stack *s)
{
    if(s->top == MAX_SIZE-1)
    {
        return 1;
    }
    return 0;
}

int main()
{
    stack A, B;
    create(&A);
    create(&B);
    push(&A, 10);
    push(&A, 12);
    push(&A, 14);
    printf("%d ", pop(&A));
    printf("%d ", pop(&A));
    return 0;
}
