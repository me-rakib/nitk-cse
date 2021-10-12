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
struct Node *delete_nth_node(struct Node *head, int pos);

int main()
{
    // redirecting input and output
    freopen("f_input.txt", "r", stdin);
    freopen("f_output.txt", "w", stdout);

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
    scanf("%d", &pos);
    head = delete_nth_node(head, pos);
    printf("After deleting %d nth node: ", pos);
    print(head);
    return 0;
}

// function to delete node from a specified position
struct Node *delete_nth_node(struct Node *head, int pos)
{
    struct Node *temp = head;
    if (pos == 1)
    {
        head = temp->next;
        head->pre = NULL;
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
        if (temp1->next == NULL)  // for deleting last node
        {
            temp->next = NULL;
            free(temp1);
            temp1 = NULL;
        }
        else
        {
            temp->next = temp1->next;
            temp1->next->pre = temp;
            free(temp1);
            temp1 = NULL;
        }
    }
    return head;
}

// function to insert node at the end
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
