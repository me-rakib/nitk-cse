#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *pre;
    int data;
    struct Node *next;
};

// function decleration
void print(struct Node *head);
struct Node *insert(struct Node *head, int data);
struct Node *insert_node_at_nth_position(struct Node *head, int data, int pos);

int main()
{
    // redirecting input and output
    freopen("c_input.txt", "r", stdin);
    freopen("c_output.txt", "w", stdout);

    struct Node *head = NULL;
    int i, n, data, pos;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &data);
        head = insert(head, data);
    }
    printf("List: ");
    print(head);
    scanf("%d %d", &data, &pos);
    head = insert_node_at_nth_position(head, data, pos);
    printf("List after inserting %d in position %d: ", data, pos);
    print(head);
    return 0;
}

struct Node *insert_node_at_nth_position(struct Node *head, int data, int pos)
{
    struct Node *newP = (struct Node *)malloc(sizeof(struct Node));
    newP->pre = NULL;
    newP->data = data;
    newP->next = NULL;
    if (pos == 1)
    {
        head->pre = newP;
        newP->next = head;
        head = newP;
    }
    else
    {
        struct Node *temp1 = head, *temp2 = NULL;
        int i;
        for (i = 0; i < pos - 2; i++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        if (temp2 == NULL) //if want to insert after the last element
        {
            temp1->next = newP;
            newP->pre = temp1;
        }
        else
        {
            newP->pre = temp1;
            temp1->next = newP;
            newP->next = temp2;
            temp2->pre = newP;
        }
    }
    return head;
}

// function to inserting some node at the end
struct Node *insert(struct Node *head, int data)
{
    struct Node *newP = (struct Node *)malloc(sizeof(struct Node));
    newP->pre = NULL;
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
        newP->pre = temp;
        temp->next = newP;
    }
    return head;
}

// function to print the element of the node
void print(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.");
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
