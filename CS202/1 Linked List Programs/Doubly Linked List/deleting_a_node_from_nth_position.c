#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

struct Node *insert(struct Node *head, int data);
void print(struct Node *head);
struct Node *delete (struct Node *head, int pos);

int main()
{
    int n, i, data, del;
    struct Node *head = NULL;
    printf("Enter Total Node: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        head = insert(head, data);
    }
    print(head);
    printf("Position to delete: ");
    scanf("%d", &del);
    head = delete (head, del);
    print(head);
    return 0;
}

struct Node *insert(struct Node *head, int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;

    if (head == NULL)
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

void print(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

struct Node *delete (struct Node *head, int pos)
{
    struct Node *temp = head;

    if (pos == 1)
    {
        head = head->next;
        free(head->prev);
        head->prev = NULL;
    }
    else
    {
        struct Node *temp1 = NULL;
        int i;
        for (i = 0; i < pos - 2; i++)
        {
            temp = temp->next;
        }
        temp1 = temp->next;
        if (temp1->next == NULL)
        {
            temp->next = NULL;
            free(temp1);
            temp1 = NULL;
        }
        else
        {
            temp->next = temp1->next;
            temp1->next->prev = temp;
            free(temp1);
            temp1 = NULL;
        }
    }
    return head;
}