#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};

// functions decleration
bool is_empty(struct Node *front, struct Node *rear);
void enqueue(int data, struct Node **front, struct Node **rear);
void dequeue(struct Node **front, struct Node **rear);
void print(struct Node **front, struct Node **rear);
void queue();

int main()
{
}

void queue(int data)
{
    struct Node *front = NULL, *rear = NULL;
}

// inserting element into the queue
void enqueue(int data, struct Node **front, struct Node **rear)
{
    struct Node *newP = (struct Node *)malloc(sizeof(struct Node));
    newP->data = data;
    newP->next = newP;

    if (is_empty(*front, *rear))
    {
        *front = newP;
        *rear = newP;
    }
    else
    {
        (*rear)->next = newP;
        newP->next = *front;
        *rear = newP;
    }
}

// deleting element from queue
void dequeue(struct Node **front, struct Node **rear)
{
    struct Node *temp = *front;
    if (is_empty(*front, *rear))
    {
        printf("\nNothing to dequeue\n");
        return;
    }
    else if (*front == *rear)
    {
        *front = NULL;
        *rear = NULL;
    }
    else
    {
        *front = (*front)->next;
        (*rear)->next = (*front);
    }
    free(temp);
}

// printing the element of the queue
void print(struct Node **front, struct Node **rear)
{
    if (is_empty(*front, *rear))
    {
        printf("\nQueue is empty\n");
    }
    struct Node *temp = *front;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != (*rear)->next);
    printf("\n");
}

bool is_empty(struct Node *front, struct Node *rear)
{
    return (front == NULL && rear == NULL);
}