#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head =NULL;

void print() 
{
    struct Node * temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    
}

void insert_data(int data) 
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp ->next = NULL;
    if(head == NULL) 
    {
        head = temp;
    }
    else 
    {
        struct Node * temp1 = head;
        while(temp1->next != NULL) 
        {
            temp1 = temp1->next;
        }
        temp1->next = temp;
    }
}

void reverse(struct Node *p)
{
    if(p->next==NULL) 
    {
        head = p;
        return;
    }
    reverse(p->next);

    struct Node *q = p->next; 
    q->next = p;
    p->next = NULL;
}

int main() 
{
    insert_data(5);
    insert_data(1);
    insert_data(4);
    insert_data(40);
    print();
    reverse(head);
    print();
}