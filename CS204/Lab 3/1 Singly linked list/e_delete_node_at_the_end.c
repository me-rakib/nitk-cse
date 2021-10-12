#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// functions
void print(struct Node *head);
struct Node *insert(struct Node *head, int data);
struct Node *delete (struct Node *head);

int main()
{
    // redirecting input and output
    freopen("e_input.txt", "r", stdin);
    freopen("e_output.txt", "w", stdout);

    struct Node *head = NULL;
    int i, n, data;
    scanf("%d", &n); //total node
    for (i = 0; i < n; i++)
    {
        scanf("%d", &data);
        head = insert(head, data);
    }
    printf("List: ");
    print(head);
    head = delete (head);
    printf("After deleting last node: ");
    print(head);
    return 0;
}

// delete last node
struct Node *delete (struct Node *head)
{
    struct Node *temp = head;
    if (head == NULL)
    {
        return head;
    }
    else
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
    return head;
}

// function to insert some data at the end
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
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newP;
    }
    return head;
}

// function to print data
void print(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty");
    }
    else
    {
        while (head != NULL)
        {
            printf("%d ", head->data);
            head = head->next;
        }
    }
    printf("\n");
}