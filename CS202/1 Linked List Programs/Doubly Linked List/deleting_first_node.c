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
struct Node *delete(struct Node *head);

int main()
{
    int n, i, data;
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
    head = delete(head);
    print(head);
    return 0;
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

void print(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

struct Node *delete(struct Node *head)
{
    struct Node *temp = head;
    head = head->next;
    head->prev = NULL;
    free(temp);
    temp = NULL;
    return head;
}