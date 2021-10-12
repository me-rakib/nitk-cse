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
struct Node *insert_at_nth_position(struct Node *tail, int data, int pos);
void print(struct Node *tail);

int main()
{
    // redirecting input and output
    freopen("c_input.txt", "r", stdin);
    freopen("c_output.txt", "w", stdout);

    struct Node *tail = NULL;
    int i, n, data, pos;
    scanf("%d", &n); // total element
    for (i = 0; i < n; i++)
    {
        scanf("%d", &data);
        tail = insert(tail, data);
    }
    printf("List: ");
    print(tail);
    scanf("%d %d", &data, &pos);
    tail = insert_at_nth_position(tail, data, pos);
    printf("After inserting %d in position %d: ", data, pos);
    print(tail);
    return 0;
}

// function to insert node at nth position
struct Node *insert_at_nth_position(struct Node *tail, int data, int pos)
{
    struct Node *newP = (struct Node *)malloc(sizeof(struct Node)), *temp1 = tail->next;
    newP->prev = newP;
    newP->data = data;
    newP->next = newP;
    if (pos == 1)
    {
        newP->next = temp1;
        temp1->prev = newP;
        newP->prev = tail;
        tail->next = newP;
    }
    else
    {
        int i;
        for (i = 0; i < pos - 2; i++)
        {
            temp1 = temp1->next;
        }
        struct Node *temp2 = temp1->next;
        if (temp2 == tail->next)
        {
            tail = newP;
        }
        newP->prev = temp1;
        temp1->next = newP;
        newP->next = temp2;
        temp2->prev = newP;
    }
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