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
void print(struct Node *tail);

int main()
{
    // redirecting input and output
    freopen("b_input.txt", "r", stdin);
    freopen("b_output.txt", "w", stdout);

    struct Node *tail = NULL;
    int i, n, data;
    scanf("%d", &n); // total element
    for (i = 0; i < n; i++)
    {
        scanf("%d", &data);
        tail = insert(tail, data);
        print(tail);
    }
    return 0;
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
        tail->next->prev = newP;
        newP->next = tail->next;
        newP->prev = tail;
        tail->next = newP;
        tail = newP;

        // struct Node *temp = tail->next;
        // tail->next = newP;
        // newP->prev = tail;
        // newP->next = temp;
        // temp->prev = newP;
        // tail = newP;
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