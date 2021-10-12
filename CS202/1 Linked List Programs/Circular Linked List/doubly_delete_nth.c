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

struct Node *insert(struct Node *tail, int data)
{
    struct Node *newP = (struct Node *)malloc(sizeof(struct Node));
    newP->data = data;
    if (tail == NULL)
    {
        newP->next = newP;
        newP->prev = newP;
        tail = newP;
    }
    else
    {
        struct Node *temp = tail->next;
        newP->prev = tail;
        tail->next = newP;
        newP->next = temp;
        temp->prev = newP;
        tail = newP;
    }
    return tail;
}

struct Node *delete_nth(struct Node *tail, int pos)
{
    struct Node *temp = tail->next, *temp1 = NULL;
    int i;
    for (i = 0; i < pos - 2; i++)
    {
        temp = temp->next;
    }

    if (temp == tail)
    {
        temp = tail->prev;
        temp->next = tail->next;
        tail->next->prev = temp;
        free(tail);
        tail = temp;
    }
    else
    {
        temp1 = temp->next;
        temp->next = temp1->next;
        temp1->next->prev = temp;
        free(temp1);
        temp1 = NULL;
    }
    return tail;
}

int main()
{
    struct Node *tail = NULL;
    tail = insert(tail, 10);
    tail = insert(tail, 12);
    tail = insert(tail, 14);
    tail = insert(tail, 16);
    print(tail);
    tail = delete_nth(tail, 4);
    print(tail);
    return 0;
}