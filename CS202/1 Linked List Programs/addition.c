#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void print(struct Node *head)
{
    if (head == NULL)
    {
        printf("Nothing to print in the list");
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

struct Node *insert(struct Node *head) 
{
    int n, last_digit;
    printf("Enter Number: ");
    scanf("%d", &n);
    struct Node *newP = NULL;
    while(n!=0)
    {
        newP = (struct Node *)malloc(sizeof(struct Node));
        last_digit = n % 10;
        newP->data = last_digit;
        newP->next = NULL;
        if(head == NULL)
        {
            head = newP;
        }
        else
        {
            struct Node *temp = head;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newP;
        }
        n /= 10;
    }
    return head;
}

struct Node *reverse(struct Node *head) 
{
    struct Node *current = head, *prev = NULL, *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

struct Node *push(struct Node *head, int val) 
{
    struct Node *newP = (struct Node *)malloc(sizeof(struct Node));
    newP->data = val;
    newP->next = head;
    head = newP;
    return head;
}

struct Node *add(struct Node *head1, struct Node *head2)
{
    
}

int main()
{
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;
    head1 = insert(head1);
    head2 = insert(head2);
    print(head1);
    print(head2);
    
    return 0;
}