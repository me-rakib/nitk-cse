#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *insert(struct Node *head, int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
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
    }
    return head;
}

void print(struct Node *head) 
{
    while(head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

struct Node *insert_as_sorted(struct Node *head, int data) 
{
    struct Node *newP = (struct Node *)malloc(sizeof(struct Node)), *temp=head;
    newP->data = data;
    newP->next = NULL;
    if(head == NULL ||  newP->data < head->next->data)
    {
        newP->next = head;
        head = newP;
    }
    else
    {
        while (temp->next != NULL && temp->next->data < newP->data)
        {
            temp = temp->next;
        }
        newP->next = temp->next;
        temp->next = newP;
    }
    return head;
}

int main()
{
    struct Node *head = NULL;
    head = insert(head, 102);
    head = insert(head, 103);
    head = insert(head, 104);
    head = insert(head, 105);
    head = insert(head, 106);
    print(head);
    head = insert_as_sorted(head, 101);
    print(head);
}