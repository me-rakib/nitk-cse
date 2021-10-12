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
int count_node(struct Node *head);

int main()
{
    // redirecting input and output
    freopen("6_output.txt", "w", stdout);

    struct Node *head = NULL;
    head = insert(head, 10);
    head = insert(head, 20);
    head = insert(head, 30);
    head = insert(head, 40);
    printf("Data: ");
    print(head);
    printf("Total Node: %d", count_node(head));
    return 0;
}

int count_node(struct Node *head)
{
    int count = 0;
    while(head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

// function to insert data at the beginning
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