#include<stdio.h>
#include<stdlib.h>

struct Node {
    struct Node * prev;
    int data;
    struct Node * next;
};

void print(struct Node *head) 
{
    while(head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

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
        struct Node *temp1 = head;
        while (temp1->next != NULL)
        {
            temp1 = temp1->next;
        }
        temp1->next = temp;
        temp->prev = temp1;
    }
    return head;
}

int main()
{
    struct Node *head = NULL;
    head = insert(head, 10);
    head = insert(head, 5);
    head = insert(head, 1);
    head = insert(head, 6);
    print(head);   
}