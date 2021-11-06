#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

bool is_empty()
{
    return (front == NULL && rear == NULL);
}

int get_front()
{
    if(is_empty())
    {
        printf("Queue is empty");
        return -1;
    }
    return front->data;
}

void enqueue(int x)
{
    struct Node *newP = (struct Node *)malloc(sizeof(struct Node));
    newP->data = x;
    newP->next = NULL;
    if (front == NULL && rear == NULL)
    {
        front = newP;
        rear = newP;
    }
    else
    {
        rear->next = newP;
        rear = newP;
    }
}

void dequeue()
{
    struct Node *temp = front;
    if (front == NULL)
    {
        printf("Queue is empty\n");
    }
    else if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        front = front->next;
    }
    free(temp);
}

void print()
{
    struct Node *temp = front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    print();
    dequeue();
    dequeue();
    print();
    return 0;
}