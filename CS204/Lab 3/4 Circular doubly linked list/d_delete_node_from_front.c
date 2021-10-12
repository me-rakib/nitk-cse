#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

// function decleration
struct Node *insert(struct Node *tail, int data);
struct Node *delete (struct Node *tail);
void print(struct Node *tail);

int main()
{
    // redirecting input and output
    freopen("d_input.txt", "r", stdin);
    freopen("d_output.txt", "w", stdout);

    struct Node *tail = NULL;
    int i, n, data;
    scanf("%d", &n); // total element
    for (i = 0; i < n; i++)
    {
        scanf("%d", &data);
        tail = insert(tail, data);
    }
    printf("List: ");
    print(tail);
    printf("After deleting first node: ");
    tail = delete (tail);
    print(tail);
    return 0;
}

// function to delete data from front
struct Node *delete (struct Node *tail)
{
    struct Node *temp = tail->next;
    tail->next = temp->next;
    temp->next->prev = tail;
    free(temp);
    temp = NULL;
    return tail;
}

// function to insert data at the end
struct Node *insert(struct Node *tail, int data)
{
    struct Node *newP = (struct Node *)malloc(sizeof(struct Node));
    newP->prev = newP;
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
        newP->prev = tail;
        newP->next = temp;
        temp->prev = newP;
        tail = newP;
    }
    return tail;
}

// function to print data
void print(struct Node *tail)
{
    struct Node *temp = tail->next;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != tail->next);
    printf("\n");
}