#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * next;
};


struct Node *insert(struct Node *tail, int data) 
{
    struct Node * temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    if(tail == NULL) 
    {
        temp->next = temp;
        return temp;
    }
    else
    {
        temp->next = tail->next;
        tail->next = temp;
        tail = temp;
        return tail;
    }
}


struct Node *insert_nth(struct Node *tail, int data, int pos)
{
    struct Node *temp, *p=tail->next;
    int i;
    for(i=0; i<pos-2; i++) 
    {
        p = p->next;
    }
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = p->next;
    p->next = temp;
    if(p == tail) 
    {
        tail = temp;
    }
    return tail;
}

void print(struct Node *tail) 
{
    struct Node *p = tail->next;
    do 
    {
        printf("%d ", p->data);
        p = p->next;
    }
    while(p != tail->next);
    printf("\n");
}

struct Node * delete_nth(struct Node * tail, int pos) 
{
    struct Node *temp = tail->next, *temp1 = NULL;
    if(pos == 1)
    {
        tail->next = temp->next;
        free(temp);
        return tail;
    }
    
    int i;
    for(i=0; i<pos-2; i++) 
    {
        temp = temp->next;
    }
    temp1 = temp->next;
    temp->next = temp1->next;
    if(temp1 == tail) 
    {
        tail = temp;
    }
    free(temp1);
    temp1 = NULL;
    return tail;
}

int main()
{
    struct Node *tail = NULL;
    tail = insert(tail, 1);
    tail = insert(tail, 2);
    tail = insert(tail, 3);
    tail = insert(tail, 4);
    tail = insert(tail, 5);
    print(tail);
    tail = insert_nth(tail, 22, 4);
    print(tail);
    tail = delete_nth(tail, 1);
    print(tail);
    return 0;
}