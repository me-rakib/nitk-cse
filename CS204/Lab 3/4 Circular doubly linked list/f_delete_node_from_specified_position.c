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
struct Node *delete_nth_node(struct Node *tail, int pos);
void print(struct Node *tail);

int main()
{
    // redirecting input and output
    freopen("f_input.txt", "r", stdin);
    freopen("f_output.txt", "w", stdout);

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
    scanf("%d", &pos);
    printf("After deleting %d nth node: ", pos);
    tail = delete_nth_node(tail, pos);
    print(tail);
    return 0;
}

// function to delete nth node
struct Node *delete_nth_node(struct Node *tail, int pos)
{
    struct Node *temp1 = tail->next;
    if (pos == 1)
    {
        tail->next = temp1->next;
        temp1->next->prev = tail;
        free(temp1);
        temp1 = NULL;
    }
    else
    {
        int i;
        for (i = 0; i < pos - 2; i++)
        {
            temp1 = temp1->next;
        }
        struct Node *temp2 = temp1->next;
        temp1->next = temp2->next;
        temp2->next->prev = temp1;
        if(temp2->next == tail->next)
        {
            tail = temp1;
        }
        free(temp2);
        temp2 = NULL;
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