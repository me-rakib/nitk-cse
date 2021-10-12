#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// function decleration
struct Node *insert(struct Node *head, int data);
void print(struct Node *head);
struct Node *concate(struct Node *head1, struct Node *head2);

int main()
{
    // redirecting input and output
    freopen("8_input.txt", "r", stdin);
    freopen("8_output.txt", "w", stdout);

    struct Node *head1 = NULL, *head2 = NULL, *res = NULL;
    int i, n, data;

    // taking input for list one
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &data);
        head1 = insert(head1, data);
    }
    printf("List 1: ");
    print(head1);

    // taking input for list two
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &data);
        head2 = insert(head2, data);
    }
    printf("List 2: ");
    print(head2);

    res = concate(head1, head2);
    printf("Concatenated Result: ");
    print(res);
    return 0;
}

// function to concatenate two list
struct Node *concate(struct Node *head1, struct Node *head2)
{
    struct Node *temp1 = head1;
    while (temp1->next != NULL)
    {
        temp1 = temp1->next;
    }
    temp1->next = head2;
    return head1;
}

// function to insert node at the beginning
struct Node *insert(struct Node *head, int data)
{
    struct Node *newP = (struct Node *)malloc(sizeof(struct Node));
    newP->data = data;
    newP->next = NULL;

    if (head == NULL)
    {
        head = newP;
    }
    else
    {
        newP->next = head;
        head = newP;
    }
    return head;
}

// function to print element
void print(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}