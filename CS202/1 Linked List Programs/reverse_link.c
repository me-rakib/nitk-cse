#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *insert(struct Node *head, int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
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
}

struct Node *reverse(struct Node *head)
{
    struct Node *pre, *next, *current;
    current = head;
    pre = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = pre;
        pre = current;
        current = next;
    }
    head = pre;
    return head;
}

int main()
{
    struct Node *head = NULL;
    int i, n, num;
    printf("Enter total node: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter number: ");
        scanf("%d", &num);
        head = insert(head, num);
    }
    print(head);
    printf("\n");
    head = reverse(head);
    print(head);
}