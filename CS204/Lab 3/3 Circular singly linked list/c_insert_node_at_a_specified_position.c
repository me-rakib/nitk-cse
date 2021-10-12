#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// function decleration
struct Node *insert(struct Node *tail, int data);
struct Node *insert_at_nth_position(struct Node *tail, int data, int pos);
void print(struct Node *tail);

int main()
{
    // redicreting input and output
    freopen("c_input.txt", "r", stdin);
    freopen("c_output.txt", "w", stdout);

    struct Node *tail = NULL;
    int i, n, data, pos;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &data);
        tail = insert(tail, data);
    }
    printf("List: ");
    print(tail);
    scanf("%d %d", &data, &pos);
    tail = insert_at_nth_position(tail, data, pos);
    printf("After entering %d in position %d: ", data, pos);
    print(tail);
    return 0;
}

// function to insert node at nth position
struct Node *insert_at_nth_position(struct Node *tail, int data, int pos) 
{
    struct Node *newP = (struct Node *)malloc(sizeof(struct Node));
    newP->data = data;
    newP->next = newP;

    if(pos == 1)
    {
        newP->next = tail->next;
        tail->next = newP;
    }
    else
    {
        struct Node *temp = tail->next;
        int i;
        for(i=0; i<pos-2; i++)
        {
            temp = temp->next;
        }
        if(temp == tail)
        {
            newP->next = tail->next;
            tail->next = newP;
            tail = newP;
            return tail;
        }
        newP->next = temp->next;
        temp->next = newP;
    }
    return tail;
}

// function to insert some node at the end
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

// function to print data
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