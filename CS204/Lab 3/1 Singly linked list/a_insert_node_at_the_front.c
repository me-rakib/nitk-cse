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
        print(head);
    }
    return 0;
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