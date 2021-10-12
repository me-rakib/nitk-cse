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
struct Node *marge(struct Node *head1, struct Node *head2);

int main()
{
    // redirecting input and output
    freopen("7_input.txt", "r", stdin);
    freopen("7_output.txt", "w", stdout);

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

    printf("Marged List: ");
    res = marge(head1, head2);
    print(res);
    return 0;
}

// function to marge two list
struct Node *marge(struct Node *head1, struct Node *head2)
{
    struct Node *ptr1 = head1;
    struct Node *ptr2 = head2;
    struct Node *head = NULL;

    while (ptr1 != NULL && ptr2 != NULL)
    {
        head = insert(head, ptr1->data);
        head = insert(head, ptr2->data);
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    while (ptr1 != NULL)
    {
        head = insert(head, ptr1->data);
        ptr1 = ptr1->next;
    }
    while (ptr2 != NULL)
    {
        head = insert(head, ptr2->data);
        ptr1 = ptr2->next;
    }
    return head;
}

// function to insert node in ascending order
struct Node *insert(struct Node *head, int data)
{
    struct Node *newP = (struct Node *)malloc(sizeof(struct Node));
    newP->data = data;
    newP->next = NULL;

    if (head == NULL || data < head->data)
    {
        newP->next = head;
        head = newP;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != NULL && data > temp->next->data)
        {
            temp = temp->next;
        }
        newP->next = temp->next;
        temp->next = newP;
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