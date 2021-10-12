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
struct Node *delete_nth(struct Node *head, int pos);

int main()
{
    // redirecting input and output
    freopen("f_input.txt", "r", stdin);
    freopen("f_output.txt", "w", stdout);

    struct Node *head = NULL;
    int i, n, data, pos;
    scanf("%d", &n); //total node
    for (i = 0; i < n; i++)
    {
        scanf("%d", &data);
        head = insert(head, data);
    }
    printf("List: ");
    print(head);
    scanf("%d", &pos);
    head = delete_nth(head, pos);
    printf("List after deleting %d nth position: ", pos);
    print(head);
    return 0;
}

// deleting node from nth position
struct Node *delete_nth(struct Node *head, int pos)
{
    struct Node *temp = head;
    if (pos == 1)
    {
        head = temp->next;
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
        struct Node *temp_next = temp->next;
        temp->next = temp_next->next;
        free(temp_next);
        temp_next = NULL;
    }
    return head;
}

// function to insert data at the end
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
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newP;
    }
    return head;
}

// function to traverse and print data
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