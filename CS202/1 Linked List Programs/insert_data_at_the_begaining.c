// insert node at the beginning

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insert_data(int x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = head;
    head = temp;
}

void print()
{
    struct Node *temp;
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int n, num, i;
    printf("Enter total node: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter number: ");
        scanf("%d", &num);
        insert_data(num);
        print();
    }
}
