#include <stdio.h>
#define MAX_SIZE 100

// function decleration
void push(int data);
void pop();
void display();
int isFull();
int isEmpty();

// global variables
int top = -1;
int arr[MAX_SIZE];

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

// function to insert data into stack
void push(int data)
{
    if (isFull())
    {
        printf("\nList is full\n");
    }
    else
    {
        arr[++top] = data;
    }
}

// function to remove data from stack
void pop()
{
    if (isEmpty())
    {
        printf("\nList is empty\n");
    }
    else
    {
        top--;
    }
}

// function to print data
void display()
{
    if (isEmpty())
    {
        printf("\nStack is empty\n");
    }
    else
    {
        int i;
        for (i = 0; i <= top; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

int isEmpty()
{
    return top == -1 ? 1 : 0;
}

int isFull()
{
    return top == MAX_SIZE ? 1 : 0;
}