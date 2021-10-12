#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// function decleration
struct Node *insert(struct Node *tail, int data);
struct Node *delete_nth_node(struct Node *tail, int pos);
void print(struct Node *tail);

int main()
{
    // redicreting input and output
    freopen("f_input.txt", "r", stdin);
    freopen("f_output.txt", "w", stdout);

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
    scanf("%d", &pos);
    tail = delete_nth_node(tail, pos);
    printf("After deleting %d nth node: ", pos);
    print(tail);
    return 0;
}

// function to delete node from specified position
struct Node *delete_nth_node(struct Node *tail, int pos)
{
    struct Node *temp = tail->next;
    if (pos == 1) //deleting first node
    {
        tail->next = temp->next;
        free(temp);
        temp = NULL;
    }
    else
    {
        int i;
        for (i = 0; i < pos - 2; i++)
        {
            temp = temp->next;
        }
        struct Node *temp1 = temp->next;
        temp->next = temp1->next;
        if (temp1 == tail) //deleting last node
        {
            tail = temp;
        }
        free(temp1);
        temp1 = NULL;
    }
    return tail;
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