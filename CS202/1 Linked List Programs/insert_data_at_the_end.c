#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;

void create_node_list(int n);
void print_list();

int main()
{
    int n;
    printf("Enter total node: ");
    scanf("%d", &n);
    create_node_list(n);
    print_list();
    return 0;
}

void create_node_list(int n)
{
    int num, i;
    struct Node *temp, *temp1;
    head = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter data for node 1: ");
    scanf("%d", &num);

    head->data = num;
    head->next = NULL;

    temp = head;

    for (i = 2; i <= n; i++)
    {
        temp1 = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", i);
        scanf("%d", &num);

        temp1->data = num;
        temp1->next = NULL;

        temp->next = temp1;
        temp = temp1;
    }
}

void print_list()
{
    struct Node *temp;
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}