#include<stdio.h>
#include<stdlib.h>

struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
};

void print(struct Node *tail) 
{
    struct Node *temp = tail->next;
    do{
        printf("%d ", temp->data);
        temp = temp->next;
    }while(temp != tail->next);
    printf("\n");
}

struct Node *insert_beg(struct Node *tail, int data) 
{
    struct Node *newP = (struct Node *)malloc(sizeof(struct Node));
    newP->data = data;
    if(tail == NULL) 
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
        temp->prev = newP;
        tail->next = newP;
    }
    return tail;
}

int main()
{
    struct Node *tail = NULL;
    tail = insert_beg(tail, 200);
    tail = insert_beg(tail, 50);
    tail = insert_beg(tail, 10);
    print(tail);
}