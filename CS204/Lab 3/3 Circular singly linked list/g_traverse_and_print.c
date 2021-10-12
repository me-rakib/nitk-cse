#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// function decleration
struct Node *insert(struct Node *tail, int data);
void print(struct Node *tail);

int main()
{
    // redicreting input and output
    freopen("g_input.txt", "r", stdin);
    freopen("g_output.txt", "w", stdout);

    struct Node *tail = NULL;
    int i, n, data;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &data);
        tail = insert(tail, data);
    }
    print(tail);
    return 0;
}

// function to insert node at the end
struct Node *insert(struct Node *tail, int data)
{
    struct Node *newP = (struct Node *)malloc(sizeof(struct Node));
    newP->data = data;
    newP->next = newP;

    if (tail == NULL)
    {
        tail = newP;
    }
    else
    {
        struct Node *temp = tail->next;
        tail->next = newP;
        newP->next = temp;
        tail = newP;
    }
    return tail;
}

// function to traversal and print
void print(struct Node *tail)
{
    if (tail == NULL)
    {
        printf("List is empty");
        return;
    }
    struct Node *temp = tail->next;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != tail->next);
    printf("\n");
}