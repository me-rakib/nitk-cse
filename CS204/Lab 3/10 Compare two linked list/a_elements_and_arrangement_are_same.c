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
bool check_element_and_arrangement(struct Node *head1, struct Node *head2);

int main()
{
    // redirecting input and output
    freopen("a_input.txt", "r", stdin);
    freopen("a_output.txt", "w", stdout);

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
    if (check_element_and_arrangement(head1, head2))
    {
        printf("Both list are same by elements and arrangement wise");
    }
    else
    {
        printf("Lists are not same");
    }
    return 0;
}

// function to check elements and arrangement are same or not in both list
bool check_element_and_arrangement(struct Node *head1, struct Node *head2)
{
    struct Node *temp1 = head1, *temp2 = head2;
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data != temp2->data)
        {
            return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    if (temp1 != NULL)
    {
        return false;
    }
    if (temp2 != NULL)
    {
        return false;
    }
    return true;
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