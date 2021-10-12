#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

void print(struct Node *tail)
{
    struct Node *temp = tail->next;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != tail->next);
    printf("\n");
}

struct Node *insert_end(struct Node *tail, int data)
{
    struct Node *newP = (struct Node *)malloc(sizeof(struct Node));
    newP->data = data;
    if (tail == NULL)
    {
        newP->prev = newP;
        newP->next = newP;
        tail = newP;
    }
    else
    {
        struct Node *temp = tail->next;
        newP->next = temp;
        newP->prev = tail;
        tail->next = newP;
        temp->prev = newP;
        tail = newP;
    }
    return tail;
}

struct Node *insert_nth(struct Node *tail, int data, int pos)
{
    struct Node *newP = (struct Node *)malloc(sizeof(struct Node));
    newP->data = data;
    struct Node *temp = tail->next, *temp1 = NULL;
    int i;
    for (i = 0; i < pos - 2; i++)
    {
        temp = temp->next;
    }
    if (temp == tail)
    {
        struct Node *temp2 = tail->next;
        newP->next = temp2;
        temp2->prev = newP;
        newP->prev = tail;
        tail->next = newP;
        tail = newP;
    }
    else
    {
        temp1 = temp->next;
        temp->next = newP;
        newP->prev = temp;
        newP->next = temp1;
        temp1->prev = newP;
    }

    return tail;
}

int main()
{
    struct Node *tail = NULL;
    tail = insert_end(tail, 200);
    tail = insert_end(tail, 50);
    tail = insert_end(tail, 60);
    tail = insert_end(tail, 10);
    print(tail);
    tail = insert_nth(tail, 44, 5);
    print(tail);
}