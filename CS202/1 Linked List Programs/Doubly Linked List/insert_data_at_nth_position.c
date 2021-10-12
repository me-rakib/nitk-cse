#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

void print(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

struct Node *insert(struct Node *head, int data, int pos)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    if (pos == 1)
    {
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
    }
    else
    {
        struct Node *temp1 = head, *temp2 = NULL;
        int i;
        for (i = 0; i < pos - 2; i++)
        {
            temp1 = temp1->next;
        }
        if (temp1->next == NULL)
        {
            temp1->next = temp;
            temp->prev = temp1;
        }
        else
        {
            temp2 = temp1->next;
            temp1->next = temp;
            temp->prev = temp1;
            temp->next = temp2;
            temp2->prev = temp;
        }
    }
    return head;
}

int main()
{
    struct Node *head = NULL;
    head = insert(head, 10, 1);
    // head = insert(head, 11, 1);
    head = insert(head, 20, 2);
    head = insert(head, 30, 3);
    head = insert(head, 40, 4);
    print(head);
    head = insert(head, 100, 2);
    print(head);
    head = insert(head, 500, 1);
    print(head);
    return 0;
}