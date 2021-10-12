#include<stdio.h>
#include<stdlib.h>

struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
};

void print(struct Node *tail) 
{
    struct Node * temp = tail->next;
    do
    {
        printf("%d ",temp->data);
        temp = temp->next;
    } while (temp != tail->next);
    printf("\n");
}

struct Node * insert(struct Node *tail, int data) 
{
    struct Node *newP = (struct Node *)malloc(sizeof(struct Node));
    newP->data = data;
    if(tail == NULL) 
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

struct Node *delete_last(struct Node* tail) 
{
    struct Node *temp = tail->prev;
    temp->next = tail->next;
    tail->next->prev = temp;
    free(tail);
    tail = temp;
    return tail;
}

int main()
{
    struct Node * tail = NULL;
    tail = insert(tail, 10);
    tail = insert(tail, 12);
    tail = insert(tail, 14);
    tail = insert(tail, 16);
    print(tail);
    tail = delete_last(tail);
    print(tail);
    return 0;
}