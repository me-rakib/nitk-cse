#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};

// function decleration
struct Node *insert(struct Node *head, int data);
void print(struct Node *head);
bool is_same_element(struct Node *head1, struct Node *head2);

int main()
{
    // redirecting input and output
    freopen("b_input.txt", "r", stdin);
    freopen("b_output.txt", "w", stdout);

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
    if (is_same_element(head1, head2))
    {
        printf("ALl the elements in both lists are same");
    }
    else
    {
        printf("Elements are different");
    }
    return 0;
}

// function to marge two list
bool is_same_element(struct Node *head1, struct Node *head2)
{
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data != head2->data)  // as list is sorted
        {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    if (head1 != NULL)
    {
        return false;
    }
    if (head2 != NULL)
    {
        return false;
    }
    return true;
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