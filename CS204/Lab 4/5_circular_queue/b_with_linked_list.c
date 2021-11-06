#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};

// functions decleration
bool is_empty();
void enqueue(int data);
void dequeue();
void print();

struct Node *front = NULL, *rear = NULL;

int main()
{
    enqueue(5);
    enqueue(6);
    enqueue(7);
    enqueue(8);
    enqueue(9);
    enqueue(10);
    print();
    dequeue();
    print();
    dequeue();
    print();
}

// inserting element into the queue
void enqueue(int data)
{
    struct Node *newP = (struct Node *)malloc(sizeof(struct Node));
    newP->data = data;
    newP->next = newP;

    if (is_empty())
    {
        front = newP;
        rear = newP;
    }
    else
    {
        rear->next = newP;
        newP->next = front;
        rear = newP;
    }
}

// deleting element from queue
void dequeue()
{
    struct Node *temp = front;
    if (is_empty())
    {
        printf("\nNothing to dequeue\n");
        return;
    }
    else if (front == rear)
    {
        front = NULL;
        rear = NULL;
    }
    else
    {
        front = front->next;
        rear->next = front;
    }
    free(temp);
}

// printing the element of the queue
void print()
{
    if (is_empty())
    {
        printf("\nQueue is empty\n");
    }
    struct Node *temp = front;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != rear->next);
    printf("\n");
}

bool is_empty()
{
    return (front == NULL && rear == NULL);
}