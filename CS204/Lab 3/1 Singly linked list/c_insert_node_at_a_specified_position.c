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
struct Node *insert_at_nth_position(struct Node *head, int data, int pos);

int main()
{
    // redirecting input and output
    freopen("c_input.txt", "r", stdin);
    freopen("c_output.txt", "w", stdout);

    struct Node *head = NULL;
    int i, n, data, pos;
    scanf("%d", &n); //total node
    for (i = 0; i < n; i++)
    {
        scanf("%d", &data);
        head = insert(head, data);
    }
    printf("List: ");
    print(head);
    scanf("%d %d", &data, &pos);
    head = insert_at_nth_position(head, data, pos);
    printf("List after inserting %d in position %d: ", data, pos);
    print(head);
    return 0;
}

// function to insert data in nth position
struct Node *insert_at_nth_position(struct Node *head, int data, int pos)
{
    struct Node *newP = (struct Node *)malloc(sizeof(struct Node));
    newP->data = data;
    newP->next = NULL;
    if (pos == 1)
    {
        newP->next = head;
        head = newP;
    }
    else
    {
        struct Node *temp = head;
        int i;
        for (i = 0; i < pos - 2; i++)
        {
            temp = temp->next;
        }
        newP->next = temp->next;
        temp->next = newP;
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
