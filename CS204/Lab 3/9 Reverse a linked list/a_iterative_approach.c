#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// function decleration
void print(struct Node *head);
struct Node *insert(struct Node *head, int data);
struct Node *reverse(struct Node *head);

int main()
{
    // redirecting input and output
    freopen("a_input.txt", "r", stdin);
    freopen("a_output.txt", "w", stdout);

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
    printf("Reversed list: ");
    print(reverse(head));
    return 0;
}

// function to reverse node 
struct Node *reverse(struct Node *head)
{
    struct Node *current = head, *prev = NULL, *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

// function to insert data at the end
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
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}