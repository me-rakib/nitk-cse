#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;

void print()
{
    struct Node *temp;
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void insert(int data, int pos)
{
    struct Node *temp1 = (struct Node *)malloc(sizeof(struct Node));
    temp1->data = data;
    temp1->next = NULL;

    if (pos == 1)
    {
        temp1->next = head;
        head = temp1;
        return;
    }
    struct Node *temp2 = head;
    int i;
    for (i = 0; i < pos - 2; i++)
    {
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
}

int main()
{
    head = NULL;
    insert(2, 1);
    insert(3, 2);
    insert(5, 2);
    insert(4, 1);
    print();
}