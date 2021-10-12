#include<stdio.h>
#include<stdlib.h>

struct Node {
    struct Node * prev;
    int data;
    struct Node * next;
};

struct Node *insert(struct Node *head, int data) 
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    if(head == NULL) 
    {
        head = temp;
    }
    else
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    return head;
}

int main()
{
    struct Node * head = NULL;
    head = insert(head, 10);
    head = insert(head, 12);
    head = insert(head, 1);
    head = insert(head, 2);

    struct Node *temp = head;
    while (temp!= NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    
}