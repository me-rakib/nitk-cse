#include<stdio.h>
#include<stdbool.h>
#define MAX_SIZE 100

bool isEmpty();
void push(int x);
void pop();
int Top();

int top = -1;
int arr[MAX_SIZE];



void print()
{
    int i;
    printf("In stack: ");
    if(top==-1)
    {
        printf("Nothing to print\n");
        return;
    }
    for(i=0; i<=top; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    push(10);
    print();
    push(2);
    print();
    push(20);
    print();
    push(5);
    print();
    push(7);
    print();
    push(11);
    print();
    pop();
    print();
    pop();
    print();
    printf("%d ",Top());
}

void push(int x)
{
    if(top >= MAX_SIZE-1)
    {
        printf("Stack overflow\n");
        return;
    }
    arr[++top] = x;
}

void pop()
{
    if(top == -1)
    {
        printf("Nothing to remove\n");
        return;
    }
    top--;
}

int Top()
{
    return arr[top];
}

bool isEmpty()
{
    if(top == -1) 
    {
        return false;
    }
    return true;
}